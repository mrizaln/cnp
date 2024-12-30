#pragma once

#include "cnp/operator.hpp"
#include "cnp/order.hpp"

namespace cnp
{
    // generic concepts for testing multiple types
    // -------------------------------------------
    template <typename T, typename... Ts>
    concept AnyOf = (std::same_as<T, Ts> or ...);

    template <typename T, typename... Ts>
    concept AllOf = (std::same_as<T, Ts> and ...);
    // -------------------------------------------

    // aliases for sizeof... operator so that it's easier to read
    // ----------------------------------------------------------
    template <std::size_t N, typename... Ts>
    concept Sized = sizeof...(Ts) == N;

    template <std::size_t N, typename... Ts>
    concept SizedLt = sizeof...(Ts) < N;

    template <std::size_t N, typename... Ts>
    concept SizedGt = sizeof...(Ts) > N;

    template <std::size_t N, typename... Ts>
    concept SizedLe = sizeof...(Ts) <= N;

    template <std::size_t N, typename... Ts>
    concept SizedGe = sizeof...(Ts) >= N;
    // ----------------------------------------------------------

    // aliases for <type_traits>
    // -------------------------
    template <typename T>
    concept LRef = std::is_lvalue_reference_v<T>;

    template <typename T>
    concept RRef = std::is_rvalue_reference_v<T>;

    template <typename T>
    concept Ref = LRef<T> or RRef<T>;

    template <typename T>
    concept Const = std::is_const_v<T>;

    template <typename T>
    concept Ptr = std::is_pointer_v<T>;

    template <typename T>
    concept Enum = std::is_enum_v<T>;

    template <typename T>
    concept Class = std::is_class_v<T>;

    template <typename T>
    concept Int = std::is_integral_v<T>;

    template <typename T>
    concept Float = std::is_floating_point_v<T>;

    template <typename T>
    concept Signed = std::is_signed_v<T>;

    template <typename T>
    concept Unsigned = std::is_unsigned_v<T>;

    template <typename T>
    concept Fundamental = std::is_fundamental_v<T>;

    // NOTE: different from cnp::ops::Arith* concepts, they specifies whether a type can be used in arithmetic
    // operations: +, -, *, /
    template <typename T>
    concept Arithmetic = std::is_arithmetic_v<T>;

    template <typename T>
    concept Trivial = std::is_trivial_v<T>;

    template <typename T>
    concept TrivialCopy = std::is_trivially_copyable_v<T>;

    template <typename T>
    concept TrivialMove = std::is_trivially_move_constructible_v<T>
                      and std::is_trivially_move_assignable_v<T>;

    template <typename T>
    concept Empty = std::is_empty_v<T>;
    // -------------------------
}
