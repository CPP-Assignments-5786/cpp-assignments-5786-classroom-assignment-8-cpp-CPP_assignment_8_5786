/**
 * @file Formatter.hpp
 * @brief Template class with specializations for formatting values
 *
 * This file demonstrates class template specialization by providing
 * different formatting behavior for different types.
 *
 * Students must implement the specializations marked with "Must be implemented".
 *
 * Topics covered:
 * - Primary class template
 * - Full class specializations
 * - Different behavior per type
 * - decltype usage for return types
 */

#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <string>
#include <sstream>
#include <iomanip>

namespace metaengine {

    // ============================================================
    //                    PRIMARY TEMPLATE
    // ============================================================

    /**
     * @brief Primary template — formats any type using ostringstream
     *
     * Required static method:
     *   - static std::string format(const T& value);
     *       Converts value to string using std::ostringstream.
     *
     * Must be implemented.
     */
    template <typename T>
    struct Formatter {
        // ====== Must be implemented ======
        static std::string format(const T& value) { return ""; } // placeholder
    };

    // ============================================================
    //                  FULL SPECIALIZATIONS
    // ============================================================

    /**
     * @brief Full specialization for int
     *
     * Required static methods:
     *   - static std::string format(int value);
     *       Returns decimal string, e.g. "42", "-5", "0"
     *   - static std::string formatHex(int value);
     *       Returns hex string with "0x" prefix, uppercase letters, e.g. "0xFF"
     *
     * Must be implemented.
     */
    template <>
    struct Formatter<int> {
        // ====== Must be implemented ======
        static std::string format(int value) { return ""; }    // placeholder
        static std::string formatHex(int value) { return ""; } // placeholder
    };

    /**
     * @brief Full specialization for double
     *
     * Required static methods:
     *   - static std::string format(double value, int precision);
     *       Returns fixed-point string with given precision, e.g. "3.142" for (3.14159, 3)
     *   - static std::string formatScientific(double value, int precision);
     *       Returns scientific notation, e.g. "1.230e+02" for (123.0, 3)
     *   - static std::string formatWithLabel(const std::string& label, double value);
     *       Returns "label: value"
     *
     * Must be implemented.
     */
    template <>
    struct Formatter<double> {
        // ====== Must be implemented ======
        static std::string format(double value, int precision) { return ""; }                         // placeholder
        static std::string formatScientific(double value, int precision) { return ""; }               // placeholder
        static std::string formatWithLabel(const std::string& label, double value) { return ""; }    // placeholder
    };

    /**
     * @brief Full specialization for bool
     *
     * Required static methods:
     *   - static std::string format(bool value);
     *       Returns "true" or "false"
     *   - static std::string formatYesNo(bool value);
     *       Returns "Yes" or "No"
     *   - static std::string formatOnOff(bool value);
     *       Returns "ON" or "OFF"
     *
     * Must be implemented.
     */
    template <>
    struct Formatter<bool> {
        // ====== Must be implemented ======
        static std::string format(bool value) { return ""; }      // placeholder
        static std::string formatYesNo(bool value) { return ""; } // placeholder
        static std::string formatOnOff(bool value) { return ""; } // placeholder
    };

    /**
     * @brief Full specialization for std::string
     *
     * Required static methods:
     *   - static std::string format(const std::string& value);
     *       Returns value wrapped in quotes, e.g. "\"Hello World\""
     *   - static std::string formatUpper(const std::string& value);
     *       Returns all-uppercase version of value
     *   - static std::string formatLower(const std::string& value);
     *       Returns all-lowercase version of value
     *   - static std::string formatWithLabel(const std::string& label, const std::string& value);
     *       Returns "label: \"value\" (length: N)"
     *
     * Must be implemented.
     */
    template <>
    struct Formatter<std::string> {
        // ====== Must be implemented ======
        static std::string format(const std::string& value) { return ""; }                                          // placeholder
        static std::string formatUpper(const std::string& value) { return ""; }                                     // placeholder
        static std::string formatLower(const std::string& value) { return ""; }                                     // placeholder
        static std::string formatWithLabel(const std::string& label, const std::string& value) { return ""; }      // placeholder
    };

} // namespace metaengine

#endif // FORMATTER_HPP