#pragma once

#include <concepts>

namespace cnp::ops
{
    inline namespace unary
    {
        template <typename T, typename Output = T>
        concept Plus = requires (T t) {
            { +t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept Neg = requires (T t) {
            { -t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept Not = requires (T t) {
            { !t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept BitNot = requires (T t) {
            { ~t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept PreInc = requires (T t) {
            { ++t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept PostInc = requires (T t) {
            { t++ } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept PreDec = requires (T t) {
            { --t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T>
        concept PostDec = requires (T t) {
            { t-- } -> std::same_as<Output>;
        };
    }

    inline namespace binary
    {
        // arithmetic
        // ----------
        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Add = requires (Lhs l, Rhs r) {
            { l + r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept AddAssign = requires (Lhs l, Rhs r) {
            { l += r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Sub = requires (Lhs l, Rhs r) {
            { l - r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept SubAssign = requires (Lhs l, Rhs r) {
            { l -= r } -> std::same_as<Output>;
        };
        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Mul = requires (Lhs l, Rhs r) {
            { l* r } -> std::same_as<Output>;
        };
        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept MulAssign = requires (Lhs l, Rhs r) {
            { l *= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Div = requires (Lhs l, Rhs r) {
            { l / r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept DivAssign = requires (Lhs l, Rhs r) {
            { l /= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Mod = requires (Lhs l, Rhs r) {
            { l % r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept ModAssign = requires (Lhs l, Rhs r) {
            { l %= r } -> std::same_as<Output>;
        };
        // ----------

        // bitwise arithmetic
        // ----------
        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitAnd = requires (Lhs l, Rhs r) {
            { l& r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitAndAssign = requires (Lhs l, Rhs r) {
            { l &= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitOr = requires (Lhs l, Rhs r) {
            { l | r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitOrAssign = requires (Lhs l, Rhs r) {
            { l |= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitXor = requires (Lhs l, Rhs r) {
            { l ^ r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitXorAssign = requires (Lhs l, Rhs r) {
            { l ^= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept LShift = requires (Lhs l, Rhs r) {
            { l << r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept LShiftAssign = requires (Lhs l, Rhs r) {
            { l <<= r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept RShift = requires (Lhs l, Rhs r) {
            { l >> r } -> std::same_as<Output>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept RShiftAssign = requires (Lhs l, Rhs r) {
            { l >>= r } -> std::same_as<Output>;
        };
        // ----------

        // logical and relational
        // ----------------------
        template <typename Lhs, typename Rhs = Lhs>
        concept And = requires (Lhs l, Rhs r) {
            { l&& r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Or = requires (Lhs l, Rhs r) {
            { l || r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Eq = requires (Lhs l, Rhs r) {
            { l == r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Neq = requires (Lhs l, Rhs r) {
            { l != r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Lt = requires (Lhs l, Rhs r) {
            { l < r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Gt = requires (Lhs l, Rhs r) {
            { l > r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Le = requires (Lhs l, Rhs r) {
            { l <= r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs>
        concept Ge = requires (Lhs l, Rhs r) {
            { l >= r } -> std::same_as<bool>;
        };

        template <typename Lhs, typename Rhs = Lhs, typename Ord>
        concept ThreeWay = requires (Lhs l, Rhs r) {
            { l <=> r } -> std::same_as<Ord>;
        };
        // ----------------------
    }

    inline namespace combination
    {
        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Arith = Add<Lhs, Rhs, Output>    //
                    and Sub<Lhs, Rhs, Output>    //
                    and Mul<Lhs, Rhs, Output>    //
                    and Div<Lhs, Rhs, Output>    //
                    and Neg<Lhs, Output>         //
                    and Neg<Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept ArithAssign = AddAssign<Lhs, Rhs, Output>    //
                          and SubAssign<Lhs, Rhs, Output>    //
                          and MulAssign<Lhs, Rhs, Output>    //
                          and DivAssign<Lhs, Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept ArithFull = Arith<Lhs, Rhs, Output> and ArithAssign<Lhs, Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept Bit = BitAnd<Lhs, Rhs, Output>    //
                  and BitOr<Lhs, Rhs, Output>     //
                  and BitXor<Lhs, Rhs, Output>    //
                  and LShift<Lhs, Rhs, Output>    //
                  and RShift<Lhs, Rhs, Output>    //
                  and BitNot<Lhs, Output>         //
                  and BitNot<Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitAssign = BitAndAssign<Lhs, Rhs, Output>    //
                        and BitOrAssign<Lhs, Rhs, Output>     //
                        and BitXorAssign<Lhs, Rhs, Output>    //
                        and LShiftAssign<Lhs, Rhs, Output>    //
                        and RShiftAssign<Lhs, Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs, typename Output = Lhs>
        concept BitFull = Bit<Lhs, Rhs, Output> and BitAssign<Lhs, Rhs, Output>;

        template <typename Lhs, typename Rhs = Lhs>
        concept Logic = And<Lhs, Rhs>    //
                    and Or<Lhs, Rhs>     //
                    and Not<Lhs>         //
                    and Not<Rhs>;

        template <typename Lhs, typename Rhs = Lhs>
        concept Rel = Eq<Lhs, Rhs>     //
                  and Neq<Lhs, Rhs>    //
                  and Lt<Lhs, Rhs>     //
                  and Gt<Lhs, Rhs>     //
                  and Le<Lhs, Rhs>     //
                  and Ge<Lhs, Rhs>;
    }

    inline namespace access
    {
        template <typename T, typename Output = T>
        concept Deref = requires (T t) {
            { *t } -> std::same_as<Output>;
        };

        template <typename T, typename Output = T, typename I = std::size_t>
        concept Index = requires (T t, I i) {
            { t[i] } -> std::same_as<Output>;
        };

#if __cpp_multidimensional_subscript
        template <typename T, typename Output = T, typename... Is>
        concept IndexMulti = requires (T t, Is... is) {
            { t.operator[](is...) } -> std::same_as<Output>;
        };
#endif
    }
}
