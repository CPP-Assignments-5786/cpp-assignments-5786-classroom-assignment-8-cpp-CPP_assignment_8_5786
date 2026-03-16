/**
 * @file TypeInfo.hpp
 * @brief Template class with full and partial specializations for type information
 *
 * This file demonstrates template specialization by providing compile-time
 * information about different types.
 *
 * Students must implement the specializations marked with "Must be implemented".
 *
 * Topics covered:
 * - Primary template
 * - Full specialization (for int, double, bool, std::string)
 * - Partial specialization (for pointers T*)
 * - Static constexpr members
 */

#ifndef TYPEINFO_HPP
#define TYPEINFO_HPP

#include <string>

namespace metaengine {

    // ============================================================
    //                    PRIMARY TEMPLATE
    // ============================================================

    /**
     * @brief Primary template for TypeInfo — provides default info
     * for any unknown type.
     *
     * Required static members:
     *   - static constexpr const char* name = "Unknown";
     *   - static constexpr bool is_numeric = false;
     *   - static constexpr bool is_pointer = false;
     *   - static constexpr size_t size = sizeof(T);
     *   - static std::string describe();
     *       Returns: "Unknown type of size <size> bytes"
     *
     * Must be implemented.
     */
    template <typename T>
    struct TypeInfo {
        // ====== Must be implemented ======
        static constexpr const char* name = "Unknown";
        static constexpr bool is_numeric = false;
        static constexpr bool is_pointer = false;
        static constexpr size_t size = sizeof(T);
        static std::string describe() { return ""; } // placeholder
    };

    // ============================================================
    //                  FULL SPECIALIZATIONS
    // ============================================================

    /**
     * @brief Full specialization for int
     *
     * Required static members:
     *   - static constexpr const char* name = "int";
     *   - static constexpr bool is_numeric = true;
     *   - static constexpr bool is_pointer = false;
     *   - static constexpr size_t size = sizeof(int);
     *   - static constexpr int min_value = -2147483647 - 1;  // INT_MIN (or use <climits>)
     *   - static constexpr int max_value = 2147483647;        // INT_MAX (or use <climits>)
     *   - static std::string describe();
     *       Returns: "int: numeric type, size 4 bytes, range [-2147483648, 2147483647]"
     *
     * Must be implemented.
     */
    template <>
    struct TypeInfo<int> {
        // ====== Must be implemented ======
        static constexpr const char* name = "int";
        static constexpr bool is_numeric = false;   // placeholder: should be true
        static constexpr bool is_pointer = false;
        static constexpr size_t size = sizeof(int);
        static constexpr int min_value = 0;          // placeholder
        static constexpr int max_value = 0;          // placeholder
        static std::string describe() { return ""; } // placeholder
    };

    /**
     * @brief Full specialization for double
     *
     * Required static members:
     *   - static constexpr const char* name = "double";
     *   - static constexpr bool is_numeric = true;
     *   - static constexpr bool is_pointer = false;
     *   - static constexpr size_t size = sizeof(double);
     *   - static std::string describe();
     *       Returns: "double: floating-point type, size 8 bytes, epsilon 1e-9"
     *
     * Must be implemented.
     */
    template <>
    struct TypeInfo<double> {
        // ====== Must be implemented ======
        static constexpr const char* name = "double";
        static constexpr bool is_numeric = false;   // placeholder: should be true
        static constexpr bool is_pointer = false;
        static constexpr size_t size = sizeof(double);
        static std::string describe() { return ""; } // placeholder
    };

    /**
     * @brief Full specialization for bool
     *
     * Required static members:
     *   - static constexpr const char* name = "bool";
     *   - static constexpr bool is_numeric = false;
     *   - static constexpr bool is_pointer = false;
     *   - static constexpr size_t size = sizeof(bool);
     *   - static std::string describe();
     *       Returns: "bool: boolean type, size 1 byte"
     *
     * Must be implemented.
     */
    template <>
    struct TypeInfo<bool> {
        // ====== Must be implemented ======
        static constexpr const char* name = "bool";
        static constexpr bool is_numeric = false;
        static constexpr bool is_pointer = false;
        static constexpr size_t size = sizeof(bool);
        static std::string describe() { return ""; } // placeholder
    };

    /**
     * @brief Full specialization for std::string
     *
     * Required static members:
     *   - static constexpr const char* name = "string";
     *   - static constexpr bool is_numeric = false;
     *   - static constexpr bool is_pointer = false;
     *   - static constexpr size_t size = sizeof(std::string);
     *   - static std::string describe();
     *       Returns: "string: text type, size <size> bytes" (size is platform-dependent)
     *
     * Must be implemented.
     */
    template <>
    struct TypeInfo<std::string> {
        // ====== Must be implemented ======
        static constexpr const char* name = "string";
        static constexpr bool is_numeric = false;
        static constexpr bool is_pointer = false;
        static constexpr size_t size = sizeof(std::string);
        static std::string describe() { return ""; } // placeholder
    };

    // ============================================================
    //                  PARTIAL SPECIALIZATION
    // ============================================================

    /**
     * @brief Partial specialization for any pointer type T*
     *
     * This demonstrates partial specialization — it applies to ALL pointer
     * types regardless of what T is.
     *
     * Required static members:
     *   - static constexpr const char* name = "pointer";
     *   - static constexpr bool is_numeric = false;
     *   - static constexpr bool is_pointer = true;
     *   - static constexpr size_t size = sizeof(T*);
     *   - static std::string describe();
     *       Returns: "pointer to <T_name>, size <size> bytes"
     *       where <T_name> is obtained from TypeInfo<T>::name
     *
     * Must be implemented.
     */
    template <typename T>
    struct TypeInfo<T*> {
        // ====== Must be implemented ======
        static constexpr const char* name = "pointer";
        static constexpr bool is_numeric = false;
        static constexpr bool is_pointer = false;    // placeholder: should be true
        static constexpr size_t size = sizeof(T*);
        static std::string describe() { return ""; } // placeholder
    };

} // namespace metaengine

#endif // TYPEINFO_HPP