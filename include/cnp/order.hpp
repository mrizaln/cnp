#pragma once

#include "cnp/operator.hpp"

#include <compare>

namespace cnp::ord
{
    namespace detail
    {
        enum class OrderCategory
        {
            Unordered,
            PartialOrder,
            WeakOrder,
            StrongOrder
        };

        template <typename, typename>
        struct OrderTraits
        {
            static constexpr auto category = OrderCategory::Unordered;
        };

        template <typename Lhs, typename Rhs>
            requires ops::ThreeWay<Lhs, Rhs, std::partial_ordering>
        struct OrderTraits<Lhs, Rhs>
        {
            static constexpr auto category = OrderCategory::PartialOrder;
        };

        template <typename Lhs, typename Rhs>
            requires ops::ThreeWay<Lhs, Rhs, std::weak_ordering>
        struct OrderTraits<Lhs, Rhs>
        {
            static constexpr auto category = OrderCategory::WeakOrder;
        };

        template <typename Lhs, typename Rhs>
            requires ops::ThreeWay<Lhs, Rhs, std::strong_ordering>
        struct OrderTraits<Lhs, Rhs>
        {
            static constexpr auto category = OrderCategory::StrongOrder;
        };
    }

    template <typename Lhs, typename Rhs = Lhs>
    concept Unordered = detail::OrderTraits<Lhs, Rhs>::category == detail::OrderCategory::Unordered;

    template <typename Lhs, typename Rhs = Lhs>
    concept PartialOrd = detail::OrderTraits<Lhs, Rhs>::category == detail::OrderCategory::PartialOrder;

    template <typename Lhs, typename Rhs = Lhs>
    concept WeakOrd = detail::OrderTraits<Lhs, Rhs>::category == detail::OrderCategory::WeakOrder;

    template <typename Lhs, typename Rhs = Lhs>
    concept StrongOrd = detail::OrderTraits<Lhs, Rhs>::category == detail::OrderCategory::StrongOrder;

    template <typename Lhs, typename Rhs = Lhs>
    concept Ord = PartialOrd<Lhs, Rhs> or WeakOrd<Lhs, Rhs> or StrongOrd<Lhs, Rhs>;
}
