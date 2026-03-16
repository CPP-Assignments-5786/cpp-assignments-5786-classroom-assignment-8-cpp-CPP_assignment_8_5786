/**
 * @file DecltypeUtils.hpp
 * @brief Utility functions demonstrating decltype and auto return types
 *
 * This file demonstrates the use of decltype to deduce types
 * at compile time, enabling generic code that adapts to
 * the types it operates on.
 *
 * Students must implement the functions marked with "Must be implemented".
 *
 * Topics covered:
 * - decltype for type deduction
 * - auto return type
 * - Trailing return types
 * - Type deduction in expressions
 */

#ifndef DECLTYPEUTILS_HPP
#define DECLTYPEUTILS_HPP

#include <string>
#include <type_traits>

namespace metaengine {

    // ============================================================
    //               DECLTYPE-BASED FUNCTIONS
    // ============================================================

    /**
     * @brief Add two values, deducing the return type with decltype
     *
     * @tparam A First operand type
     * @tparam B Second operand type
     * @return The sum, with type deduced by decltype
     * Must be implemented.
     */
    template <typename A, typename B>
    auto add(const A& a, const B& b) -> decltype(a + b) {
        // ====== Must be implemented ======
        return {}; // placeholder
    }

    /**
     * @brief Multiply two values, deducing the return type with decltype
     * Must be implemented.
     */
    template <typename A, typename B>
    auto multiply(const A& a, const B& b) -> decltype(a * b) {
        // ====== Must be implemented ======
        return {}; // placeholder
    }

    /**
     * @brief Return the larger of two values, deducing return type
     *
     * @tparam A First type
     * @tparam B Second type
     * Must be implemented.
     */
    template <typename A, typename B>
    auto maxOf(const A& a, const B& b) -> decltype(a + b) {
        // ====== Must be implemented ======
        return {}; // placeholder
    }

    /**
     * @brief Return the smaller of two values
     * Must be implemented.
     */
    template <typename A, typename B>
    auto minOf(const A& a, const B& b) -> decltype(a + b) {
        // ====== Must be implemented ======
        return {}; // placeholder
    }

    // ============================================================
    //              DECLTYPE WITH TYPE CHECKING
    // ============================================================

    /**
     * @brief Check at compile time if the result of adding A+B is a floating point type
     *
     * @tparam A First type
     * @tparam B Second type
     * Must be implemented.
     */
    template <typename A, typename B>
    constexpr bool isAddResultFloating() {
        // ====== Must be implemented ======
        return false; // placeholder
    }

    /**
     * @brief Check at compile time if the result of multiplying A*B is integral
     *
     * @tparam A First type
     * @tparam B Second type
     * Must be implemented.
     */
    template <typename A, typename B>
    constexpr bool isMulResultIntegral() {
        // ====== Must be implemented ======
        return false; // placeholder
    }

    /**
     * @brief Get a string description of the type produced by A + B
     *
     * @tparam A First type
     * @tparam B Second type
     * Must be implemented.
     */
    template <typename A, typename B>
    std::string addResultTypeName() {
        // ====== Must be implemented ======
        return ""; // placeholder
    }

} // namespace metaengine

#endif // DECLTYPEUTILS_HPP