#pragma once

#include <utility>

namespace cnp::fn
{
    template <typename F, typename Ret, typename... Args>
    concept Fn = requires (const F cf, Args... args) {
        { cf(std::forward<Args>(args)...) } -> std::same_as<Ret>;
    };

    template <typename F, typename Ret, typename... Args>
    concept FnMut = requires (F f, Args... args) {
        { f(std::forward<Args>(args)...) } -> std::same_as<Ret>;
    };

    template <typename F, typename Ret, typename... Args>
    concept FnPtr = requires (F f, Args... args) {
        requires std::is_pointer_v<F> or std::is_empty_v<F>;
        { f(std::forward<Args>(args)...) } -> std::same_as<Ret>;
    };

    template <typename F, typename Ret, typename... Args>
    concept FnNoexcept = requires (const F cf, Args... args) {
        { cf(std::forward<Args>(args)...) } noexcept -> std::same_as<Ret>;
    };

    template <typename F, typename Ret, typename... Args>
    concept FnMutNoexcept = requires (F f, Args... args) {
        { f(std::forward<Args>(args)...) } noexcept -> std::same_as<Ret>;
    };

    template <typename F, typename Ret, typename... Args>
    concept FnPtrNoexcept = requires (F f, Args... args) {
        requires std::is_pointer_v<F> or std::is_empty_v<F>;
        { f(std::forward<Args>(args)...) } noexcept -> std::same_as<Ret>;
    };
}
