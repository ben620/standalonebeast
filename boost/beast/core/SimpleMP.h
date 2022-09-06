#pragma once
#include <type_traits>

namespace smp{

template<bool B> using mp_bool = std::integral_constant<bool, B>;
using mp_true = mp_bool<true>;
using mp_false = mp_bool<false>;
template<class T> using mp_to_bool = mp_bool<static_cast<bool>(T::value)>;


template<class... T> struct mp_list {};

template<class V, class... T> constexpr std::size_t cx_count()
{
    constexpr bool a[] = { false, std::is_same<T, V>::value... };

    std::size_t r = 0;

    for (std::size_t i = 1; i < sizeof...(T) + 1; ++i)
    {
        r += a[i];
    }

    return r;
}

template<std::size_t N> using mp_size_t = std::integral_constant<std::size_t, N>;

template<class L, class V> struct mp_count_impl;


template<template<class...> class L, class... T, class V> struct mp_count_impl<L<T...>, V>
{
    using type = mp_size_t<cx_count<V, T...>()>;
};

template<class L, class V> using mp_count = typename mp_count_impl<L, V>::type;

template<class... T> using mp_all = mp_bool< mp_count< mp_list<mp_to_bool<T>...>, mp_false >::value == 0 >;




template<std::size_t N> struct mp_with_index_impl_
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        if (i < N / 2)
        {
            return mp_with_index_impl_<N / 2>::template call<K>(i, std::forward<F>(f));
        }
        else
        {
            return mp_with_index_impl_<N - N / 2>::template call<K + N / 2>(i - N / 2, std::forward<F>(f));
        }
    }
};

template<> struct mp_with_index_impl_<0>
{
};

template<> struct mp_with_index_impl_<1>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t /*i*/, F&& f)
    {
        return std::forward<F>(f)(mp_size_t<K + 0>());
    }
};

template<> struct mp_with_index_impl_<2>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        }
    }
};

template<> struct mp_with_index_impl_<3>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        }
    }
};

template<> struct mp_with_index_impl_<4>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        }
    }
};

template<> struct mp_with_index_impl_<5>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        }
    }
};

template<> struct mp_with_index_impl_<6>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        }
    }
};

template<> struct mp_with_index_impl_<7>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        }
    }
};

template<> struct mp_with_index_impl_<8>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        }
    }
};

template<> struct mp_with_index_impl_<9>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        }
    }
};

template<> struct mp_with_index_impl_<10>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        }
    }
};

template<> struct mp_with_index_impl_<11>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        }
    }
};

template<> struct mp_with_index_impl_<12>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        case 11: return std::forward<F>(f)(mp_size_t<K + 11>());
        }
    }
};

template<> struct mp_with_index_impl_<13>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        case 11: return std::forward<F>(f)(mp_size_t<K + 11>());
        case 12: return std::forward<F>(f)(mp_size_t<K + 12>());
        }
    }
};

template<> struct mp_with_index_impl_<14>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        case 11: return std::forward<F>(f)(mp_size_t<K + 11>());
        case 12: return std::forward<F>(f)(mp_size_t<K + 12>());
        case 13: return std::forward<F>(f)(mp_size_t<K + 13>());
        }
    }
};

template<> struct mp_with_index_impl_<15>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        case 11: return std::forward<F>(f)(mp_size_t<K + 11>());
        case 12: return std::forward<F>(f)(mp_size_t<K + 12>());
        case 13: return std::forward<F>(f)(mp_size_t<K + 13>());
        case 14: return std::forward<F>(f)(mp_size_t<K + 14>());
        }
    }
};

template<> struct mp_with_index_impl_<16>
{
    template<std::size_t K, class F> static constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) call(std::size_t i, F&& f)
    {
        switch (i)
        {
            default: assert(false); break;
        case 0: return std::forward<F>(f)(mp_size_t<K + 0>());
        case 1: return std::forward<F>(f)(mp_size_t<K + 1>());
        case 2: return std::forward<F>(f)(mp_size_t<K + 2>());
        case 3: return std::forward<F>(f)(mp_size_t<K + 3>());
        case 4: return std::forward<F>(f)(mp_size_t<K + 4>());
        case 5: return std::forward<F>(f)(mp_size_t<K + 5>());
        case 6: return std::forward<F>(f)(mp_size_t<K + 6>());
        case 7: return std::forward<F>(f)(mp_size_t<K + 7>());
        case 8: return std::forward<F>(f)(mp_size_t<K + 8>());
        case 9: return std::forward<F>(f)(mp_size_t<K + 9>());
        case 10: return std::forward<F>(f)(mp_size_t<K + 10>());
        case 11: return std::forward<F>(f)(mp_size_t<K + 11>());
        case 12: return std::forward<F>(f)(mp_size_t<K + 12>());
        case 13: return std::forward<F>(f)(mp_size_t<K + 13>());
        case 14: return std::forward<F>(f)(mp_size_t<K + 14>());
        case 15: return std::forward<F>(f)(mp_size_t<K + 15>());
        }
    }
};

template<std::size_t N, class F> inline constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) mp_with_index(std::size_t i, F&& f)
{
    assert(i < N);
    return mp_with_index_impl_<N>::template call<0>(i, std::forward<F>(f));
}

template<class N, class F> inline constexpr decltype(std::declval<F>()(std::declval<mp_size_t<0>>())) mp_with_index(std::size_t i, F&& f)
{
    return mp_with_index < std::size_t{ N::value } > (i, std::forward<F>(f));
}




template<class T> struct mp_identity
{
    using type = T;
};


template<class T> using mp_identity_t = typename mp_identity<T>::type;


template<class... T> struct mp_inherit : T... {};


namespace detail
{

    template<bool C, class T, class... E> struct mp_if_c_impl
    {
    };

    template<class T, class... E> struct mp_if_c_impl<true, T, E...>
    {
        using type = T;
    };

    template<class T, class E> struct mp_if_c_impl<false, T, E>
    {
        using type = E;
    };

}

template<bool C, class T, class... E> using mp_if_c = typename detail::mp_if_c_impl<C, T, E...>::type;
template<class C, class T, class... E> using mp_if = typename detail::mp_if_c_impl<static_cast<bool>(C::value), T, E...>::type;


namespace detail
{

    template<class... T> struct mp_same_impl;

    template<> struct mp_same_impl<>
    {
        using type = mp_true;
    };

    template<class T1, class... T> struct mp_same_impl<T1, T...>
    {
        using type = mp_bool< mp_count<mp_list<T...>, T1>::value == sizeof...(T) >;
    };

}

template<class... T> using mp_same = typename detail::mp_same_impl<T...>::type;


namespace detail
{
    template<template<class...> class F, class... L> struct mp_transform_impl
    {
    };

    template<template<class...> class F, template<class...> class L, class... T> struct mp_transform_impl<F, L<T...>>
    {
        using type = L<F<T>...>;
    };

    template<template<class...> class F, template<class...> class L1, class... T1, template<class...> class L2, class... T2> struct mp_transform_impl<F, L1<T1...>, L2<T2...>>
    {
        using type = L1<F<T1, T2>...>;
    };

    template<template<class...> class F, template<class...> class L1, class... T1, template<class...> class L2, class... T2, template<class...> class L3, class... T3> struct mp_transform_impl<F, L1<T1...>, L2<T2...>, L3<T3...>>
    {
        using type = L1<F<T1, T2, T3>...>;
    };
    struct list_size_mismatch
    {
    };
}
template<template<class...> class F, class... L> using mp_transform = typename mp_if<mp_same<mp_size<L>...>, detail::mp_transform_impl<F, L...>, detail::list_size_mismatch>::type;


namespace detail
{
    template<class L> struct mp_second_impl
    {

    };

    template<template<class...> class L, class T1, class T2, class... T> struct mp_second_impl<L<T1, T2, T...>>
    {
        using type = T2;
    };
}

template<class L> using mp_second = typename detail::mp_second_impl<L>::type;

namespace detail
{
    template<class T> using mpmf_wrap = mp_identity<T>;
    template<class T> using mpmf_unwrap = typename T::type;
    template<class M, class K> struct mp_map_find_impl;

    template<template<class...> class M, class... T, class K> struct mp_map_find_impl<M<T...>, K>
    {
        using U = mp_inherit<mpmf_wrap<T>...>;

        template<template<class...> class L, class... U> static mp_identity<L<K, U...>> f(mp_identity<L<K, U...>>*);
        static mp_identity<void> f(...);

        using type = mpmf_unwrap< decltype(f((U*)0)) >;
    };

}

template<class M, class K> using mp_map_find = typename detail::mp_map_find_impl<M, K>::type;

namespace detail
{
    template<class L, std::size_t I> struct mp_at_c_impl;
    template<class L, std::size_t I> struct mp_at_c_impl
    {
        using _map = mp_transform<mp_list, mp_iota<mp_size<L> >, L>;
        using type = mp_second<mp_map_find<_map, mp_size_t<I> > >;
    };
}

template<class L, std::size_t I> using mp_at_c = typename mp_if_c<(I < mp_size<L>::value), detail::mp_at_c_impl<L, I>, void>::type;
template<class L, class I> using mp_at = mp_at_c < L, std::size_t{ I::value } > ;


}