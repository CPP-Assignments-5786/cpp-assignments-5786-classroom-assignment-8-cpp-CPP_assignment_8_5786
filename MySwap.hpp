/**
 * @file MySwap.hpp
 * @brief Template swap function with specializations
 *
 * This file demonstrates function template specialization by providing
 * optimized swap implementations for specific types.
 *
 * Students must implement the functions marked with "Must be implemented".
 *
 * Topics covered:
 * - Primary function template
 * - Full function template specialization
 * - Specialization for specific types with different behavior
 */

#ifndef MYSWAP_HPP
#define MYSWAP_HPP

#include <string>
#include <iostream>

namespace metaengine {

    // ============================================================
    //                   PRIMARY TEMPLATE
    // ============================================================

    /**
     * @brief Primary template for swap — works for any type
     *
     * Uses a temporary variable to swap two values.
     * Should print: "Generic swap"
     *
     * @tparam T The type of values to swap
     * @param a First value
     * @param b Second value
     * Must be implemented.
     */
    template <typename T>
    void mySwap(T& a, T& b) {
        // ====== Must be implemented ======
    }

    // ============================================================
    //                  FULL SPECIALIZATIONS
    // ============================================================

    /**
     * @brief Full specialization for int — uses XOR swap
     *
     * XOR swap trick: a ^= b; b ^= a; a ^= b;
     * Should print: "Int XOR swap"
     * Must be implemented.
     */
    template <>
    inline void mySwap<int>(int& a, int& b) {
        // ====== Must be implemented ======
    }

    /**
     * @brief Full specialization for std::string — uses std::string::swap
     *
     * Uses the built-in string swap for efficiency.
     * Should print: "String optimized swap"
     * Must be implemented.
     */
    template <>
    inline void mySwap<std::string>(std::string& a, std::string& b) {
        // ====== Must be implemented ======
    }

    /**
     * @brief Full specialization for bool — uses logical swap
     *
     * For bools: a = a != b; b = a != b; a = a != b;
     * (This works correctly for boolean values)
     * Should print: "Bool logical swap"
     * Must be implemented.
     */
    template <>
    inline void mySwap<bool>(bool& a, bool& b) {
        // ====== Must be implemented ======
    }

} // namespace metaengine

#endif // MYSWAP_HPP