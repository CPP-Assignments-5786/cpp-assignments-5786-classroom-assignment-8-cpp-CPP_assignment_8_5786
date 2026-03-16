/**
 * @file Derivative.hpp
 * @brief Compile-time symbolic derivative computation using metaprogramming
 *
 * This file demonstrates template metaprogramming by representing
 * mathematical expressions as types and computing their derivatives
 * at compile-time.
 *
 * Expression types:
 *   Const<N>    — represents the constant N (integer)
 *   Var         — represents the variable x
 *   Add<L, R>   — represents L + R
 *   Mul<L, R>   — represents L * R
 *   Power<E, N> — represents E^N
 *
 * Students must implement the structures marked with "Must be implemented".
 *
 * Topics covered:
 * - Template metaprogramming
 * - Compile-time computation
 * - Type aliases with `using type = ...`
 * - static constexpr evaluation
 * - Symbolic differentiation rules
 */

#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

#include <string>

namespace metaengine {

    // ============================================================
    //               EXPRESSION TYPE DEFINITIONS
    // ============================================================

    /**
     * @brief Represents a compile-time integer constant
     * @tparam N The constant value
     *
     * Required static methods:
     *   - static int eval(int x);  — always returns N regardless of x
     *   - static std::string toString();  — returns the string representation of N, e.g. "5"
     *
     * Must be implemented.
     */
    template <int N>
    struct Const {
        // ====== Must be implemented ======
        static int eval(int x) { return 0; }          // placeholder
        static std::string toString() { return ""; }  // placeholder
    };

    /**
     * @brief Represents the variable x
     *
     * Required static methods:
     *   - static int eval(int x);  — returns x
     *   - static std::string toString();  — returns "x"
     *
     * Must be implemented.
     */
    struct Var {
        // ====== Must be implemented ======
        static int eval(int x) { return 0; }          // placeholder
        static std::string toString() { return ""; }  // placeholder
    };

    /**
     * @brief Represents addition: L + R
     * @tparam L Left expression type
     * @tparam R Right expression type
     *
     * Required static methods:
     *   - static int eval(int x);  — returns L::eval(x) + R::eval(x)
     *   - static std::string toString();  — returns "(L + R)" using L::toString() and R::toString()
     *
     * Must be implemented.
     */
    template <typename L, typename R>
    struct Add {
        // ====== Must be implemented ======
        static int eval(int x) { return 0; }          // placeholder
        static std::string toString() { return ""; }  // placeholder
    };

    /**
     * @brief Represents multiplication: L * R
     * @tparam L Left expression type
     * @tparam R Right expression type
     *
     * Required static methods:
     *   - static int eval(int x);  — returns L::eval(x) * R::eval(x)
     *   - static std::string toString();  — returns "(L * R)" using L::toString() and R::toString()
     *
     * Must be implemented.
     */
    template <typename L, typename R>
    struct Mul {
        // ====== Must be implemented ======
        static int eval(int x) { return 0; }          // placeholder
        static std::string toString() { return ""; }  // placeholder
    };

    /**
     * @brief Represents power: E^N (expression E raised to integer power N)
     * @tparam E The base expression type
     * @tparam N The exponent (integer)
     *
     * Required static methods:
     *   - static int eval(int x);  — returns E::eval(x) raised to the power N
     *       Special case: Power<E, 0>::eval(x) returns 1
     *   - static std::string toString();  — returns "(E^N)" using E::toString()
     *
     * Must be implemented.
     */
    template <typename E, int N>
    struct Power {
        // ====== Must be implemented ======
        static int eval(int x) { return 0; }          // placeholder
        static std::string toString() { return ""; }  // placeholder
    };

    // ============================================================
    //             COMPILE-TIME DERIVATIVE RULES
    // ============================================================

    /**
     * HOW THE DERIVATIVE SYSTEM WORKS — READ THIS FIRST
     *
     * Each `Derive<Expr>` specialization must define a *type alias*:
     *
     *   using type = <some expression type>;
     *
     * This means: "the derivative of Expr is represented by this type."
     *
     * Example — derivative of a constant (d/dx[N] = 0):
     *
     *   template <int N>
     *   struct Derive<Const<N>> {
     *       using type = Const<0>;   // the derivative is the constant 0
     *   };
     *
     * Then `Derivative<Const<5>>` (which is `Derive<Const<5>>::type`) becomes
     * `Const<0>`, and `Const<0>::eval(x)` always returns 0. 
     *
     * For Derive<Var>:   the derivative is Const<1>  (d/dx[x] = 1)
     * For Derive<Add<L,R>>: use Add<Derivative<L>, Derivative<R>>
     *                       (sum rule: d/dx[L+R] = dL + dR)
     */

    /**
     * @brief Primary template for Derive — computes d/dx of an expression
     *
     * The "type" member alias represents the derivative expression type.
     */
    template <typename Expr>
    struct Derive;

    /**
     * @brief Derivative of a constant: d/dx[N] = 0
     *
     * Inside the struct body, write:   using type = Const<0>;
     * (See the HOW IT WORKS block above for a full example.)
     *
     * Must be implemented.
     */
    template <int N>
    struct Derive<Const<N>> {
        // ====== Must be implemented ======
        // Hint: using type = Const<0>;

    };

    /**
     * @brief Derivative of Var: d/dx[x] = 1
     *
     * Inside the struct body, write:   using type = Const<1>;
     *
     * Must be implemented.
     */
    template <>
    struct Derive<Var> {
        // ====== Must be implemented ======
        // Hint: using type = Const<1>;
    };

    /**
     * @brief Derivative of Add<L, R>: Sum rule — d/dx[L + R] = dL + dR
     *
     * Inside the struct body, write:
     *   using type = Add<Derivative<L>, Derivative<R>>;
     *
     * Here, Derivative<L> (defined as a convenience alias at the bottom)
     * gives you the derivative type of L, and similarly for R.
     *
     * Must be implemented.
     */
    template <typename L, typename R>
    struct Derive<Add<L, R>> {
        // ====== Must be implemented ======
        // Hint: using type = Add<Derivative<L>, Derivative<R>>;
    };

    /**
     * @brief Derivative of Mul<L, R>: Product rule — d/dx[L * R] = dL*R + L*dR
     *
     * Inside the struct body, write:
     *   using type = Add<Mul<Derivative<L>, R>, Mul<L, Derivative<R>>>;
     *
     * Hint: Derivative<L> is the convenience alias for typename Derive<L>::type.
     * Think of it as: (dL * R) + (L * dR).
     *
     * Must be implemented.
     */
    template <typename L, typename R>
    struct Derive<Mul<L, R>> {
        // ====== Must be implemented ======
        // Hint: using type = Add<Mul<Derivative<L>, R>, Mul<L, Derivative<R>>>;

    };

    /**
     * @brief Convenience alias for getting the derivative type
     * Usage: Derivative<Expr> is the derivative type of Expr
     */
    template <typename Expr>
    using Derivative = typename Derive<Expr>::type;

} // namespace metaengine

#endif // DERIVATIVE_HPP