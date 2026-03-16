/**
 * @file main.cpp
 * @brief Demo for Physics & Math Computation Engine
 *
 * This file demonstrates template specializations, metaprogramming,
 * decltype, symbolic derivatives, and physics computations.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "TypeInfo.hpp"
#include "MySwap.hpp"
#include "Formatter.hpp"
#include "Derivative.hpp"
#include "PhysicsUnits.hpp"
#include "DecltypeUtils.hpp"

using namespace metaengine;

int main() {
    std::cout << "===== Physics & Math Computation Engine Demo =====\n\n";

    // ---- Section 1: TypeInfo specializations ----
    std::cout << "--- TypeInfo Specializations ---\n";

    std::cout << TypeInfo<int>::describe() << "\n";
    // Expected: int: numeric type, size 4 bytes, range [-2147483648, 2147483647]

    std::cout << TypeInfo<double>::describe() << "\n";
    // Expected: double: floating-point type, size 8 bytes, epsilon 1e-9

    std::cout << TypeInfo<bool>::describe() << "\n";
    // Expected: bool: boolean type, size 1 byte

    std::cout << TypeInfo<std::string>::describe() << "\n";
    // Expected: string: text type, size <size> bytes  (size is platform-dependent)

    // Partial specialization for pointers
    std::cout << TypeInfo<int*>::describe() << "\n";
    // Expected: pointer to int, size 8 bytes  (size is platform-dependent)

    std::cout << TypeInfo<double*>::describe() << "\n";
    // Expected: pointer to double, size 8 bytes

    // Unknown type
    struct CustomType {};
    std::cout << TypeInfo<CustomType>::describe() << "\n";
    // Expected: Unknown type of size 1 bytes

    // Compile-time checks
    std::cout << "int is_numeric: " << TypeInfo<int>::is_numeric << "\n";
    // Expected: int is_numeric: 1

    std::cout << "int* is_pointer: " << TypeInfo<int*>::is_pointer << "\n";
    // Expected: int* is_pointer: 1

    // ---- Section 2: Swap specializations ----
    std::cout << "\n--- Swap Specializations ---\n";

    int a = 10, b = 20;
    mySwap(a, b);
    std::cout << "After int swap: a=" << a << ", b=" << b << "\n";
    // Expected:
    // Int XOR swap
    // After int swap: a=20, b=10

    std::string s1 = "hello", s2 = "world";
    mySwap(s1, s2);
    std::cout << "After string swap: s1=" << s1 << ", s2=" << s2 << "\n";
    // Expected:
    // String optimized swap
    // After string swap: s1=world, s2=hello

    bool b1 = true, b2 = false;
    mySwap(b1, b2);
    std::cout << "After bool swap: b1=" << b1 << ", b2=" << b2 << "\n";
    // Expected:
    // Bool logical swap
    // After bool swap: b1=0, b2=1

    double d1 = 3.14, d2 = 2.71;
    mySwap(d1, d2);
    std::cout << "After double swap: d1=" << d1 << ", d2=" << d2 << "\n";
    // Expected:
    // Generic swap
    // After double swap: d1=2.71, d2=3.14

    // ---- Section 3: Formatter specializations ----
    std::cout << "\n--- Formatter Specializations ---\n";

    std::cout << Formatter<int>::format(255) << "\n";
    // Expected: 255

    std::cout << Formatter<int>::formatHex(255) << "\n";
    // Expected: 0xFF

    std::cout << Formatter<int>::formatBinary(10) << "\n";
    // Expected: 1010

    std::cout << Formatter<int>::formatWithLabel("value", 42) << "\n";
    // Expected: value: 42 (hex: 0x2A, bin: 101010)

    std::cout << Formatter<double>::format(3.14159, 3) << "\n";
    // Expected: 3.142

    std::cout << Formatter<double>::formatScientific(123.0, 3) << "\n";
    // Expected: 1.230e+02

    std::cout << Formatter<bool>::format(true) << "\n";
    // Expected: true

    std::cout << Formatter<bool>::formatYesNo(false) << "\n";
    // Expected: No

    std::cout << Formatter<bool>::formatOnOff(true) << "\n";
    // Expected: ON

    std::cout << Formatter<std::string>::format("Hello World") << "\n";
    // Expected: "Hello World"

    std::cout << Formatter<std::string>::formatUpper("Hello World") << "\n";
    // Expected: HELLO WORLD

    std::cout << Formatter<std::string>::formatLower("Hello World") << "\n";
    // Expected: hello world

    std::cout << Formatter<std::string>::formatWithLabel("name", "Alice") << "\n";
    // Expected: name: "Alice" (length: 5)

    // ---- Section 4: Symbolic Derivatives (Metaprogramming) ----
    std::cout << "\n--- Symbolic Derivatives ---\n";

    // f(x) = x
    std::cout << "f(x) = " << Var::toString() << "\n";
    // Expected: f(x) = x

    std::cout << "f(3) = " << Var::eval(3) << "\n";
    // Expected: f(3) = 3

    // f'(x) = d/dx[x] = 1
    using dVar = Derivative<Var>;
    std::cout << "f'(x) = " << dVar::toString() << "\n";
    // Expected: f'(x) = 1

    // g(x) = x + 5
    using G = Add<Var, Const<5>>;
    std::cout << "g(x) = " << G::toString() << "\n";
    // Expected: g(x) = (x + 5)

    std::cout << "g(3) = " << G::eval(3) << "\n";
    // Expected: g(3) = 8

    // g'(x) = 1 + 0 = 1
    using dG = Derivative<G>;
    std::cout << "g'(x) = " << dG::toString() << "\n";
    // Expected: g'(x) = (1 + 0)

    std::cout << "g'(3) = " << dG::eval(3) << "\n";
    // Expected: g'(3) = 1

    // h(x) = x * x (= x^2)
    using H = Mul<Var, Var>;
    std::cout << "h(x) = " << H::toString() << "\n";
    // Expected: h(x) = (x * x)

    std::cout << "h(4) = " << H::eval(4) << "\n";
    // Expected: h(4) = 16

    // h'(x) = (1*x + x*1) = 2x (unsimplified)
    using dH = Derivative<H>;
    std::cout << "h'(x) = " << dH::toString() << "\n";
    // Expected: h'(x) = ((1 * x) + (x * 1))

    std::cout << "h'(4) = " << dH::eval(4) << "\n";
    // Expected: h'(4) = 8

    // p(x) = x^3
    using P = Power<Var, 3>;
    std::cout << "p(x) = " << P::toString() << "\n";
    // Expected: p(x) = (x^3)

    std::cout << "p(2) = " << P::eval(2) << "\n";
    // Expected: p(2) = 8

    // p'(x) = 3*x^2 * 1 (chain rule, unsimplified)
    using dP = Derivative<P>;
    std::cout << "p'(2) = " << dP::eval(2) << "\n";
    // Expected: p'(2) = 12

    // ---- Section 5: Physics (constexpr) ----
    std::cout << "\n--- Physics Computations (Compile-Time) ---\n";

    // Temperature conversions
    constexpr double boiling_f = celsiusToFahrenheit(100.0);
    std::cout << "100 C = " << boiling_f << " F\n";
    // Expected: 100 C = 212 F

    constexpr double freezing_c = fahrenheitToCelsius(32.0);
    std::cout << "32 F = " << freezing_c << " C\n";
    // Expected: 32 F = 0 C

    // Distance conversions
    constexpr double marathon_miles = kmToMiles(42.195);
    std::cout << "Marathon: " << std::fixed << std::setprecision(2)
              << marathon_miles << " miles\n";
    // Expected: Marathon: 26.22 miles

    // Energy computations
    constexpr double ke = kineticEnergy(10.0, 5.0);
    std::cout << "KE(10kg, 5m/s) = " << ke << " J\n";
    // Expected: KE(10kg, 5m/s) = 125.00 J

    constexpr double pe = potentialEnergy(10.0, 20.0);
    std::cout << "PE(10kg, 20m) = " << pe << " J\n";
    // Expected: PE(10kg, 20m) = 1961.33 J

    constexpr double e_mc2 = massEnergy(1.0);
    std::cout << std::defaultfloat;
    std::cout << "E=mc^2 for 1kg: " << e_mc2 << " J\n";
    // Expected: E=mc^2 for 1kg: 8.98755e+16 J

    constexpr double fall = freeFallDistance(3.0);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Free fall (3s): " << fall << " m\n";
    // Expected: Free fall (3s): 44.13 m

    // Dimensional analysis
    std::cout << "\n--- Dimensional Analysis ---\n";

    std::cout << "Velocity: " << Velocity::toString() << "\n";
    // Expected: Velocity: Dim[M=0, L=1, T=-1]

    std::cout << "Energy: " << Energy::toString() << "\n";
    // Expected: Energy: Dim[M=1, L=2, T=-2]

    // velocity * time = length
    using VT = DimMultiply<Velocity, Time>::type;
    std::cout << "Velocity * Time = " << VT::toString() << "\n";
    // Expected: Velocity * Time = Dim[M=0, L=1, T=0]

    // energy / force = length
    using EF = DimDivide<Energy, Force>::type;
    std::cout << "Energy / Force = " << EF::toString() << "\n";
    // Expected: Energy / Force = Dim[M=0, L=1, T=0]

    // ---- Section 6: decltype ----
    std::cout << "\n--- decltype Utilities ---\n";
    std::cout << std::defaultfloat;

    auto result1 = add(3, 4.5);
    std::cout << "add(3, 4.5) = " << result1 << "\n";
    // Expected: add(3, 4.5) = 7.5

    auto result2 = multiply(3, 4);
    std::cout << "multiply(3, 4) = " << result2 << "\n";
    // Expected: multiply(3, 4) = 12

    auto result3 = maxOf(3, 4.5);
    std::cout << "maxOf(3, 4.5) = " << result3 << "\n";
    // Expected: maxOf(3, 4.5) = 4.5

    auto result4 = minOf(3, 4.5);
    std::cout << "minOf(3, 4.5) = " << result4 << "\n";
    // Expected: minOf(3, 4.5) = 3

    std::cout << "int + double is floating: " << isAddResultFloating<int, double>() << "\n";
    // Expected: int + double is floating: 1

    std::cout << "int + int is floating: " << isAddResultFloating<int, int>() << "\n";
    // Expected: int + int is floating: 0

    std::cout << "int * int is integral: " << isMulResultIntegral<int, int>() << "\n";
    // Expected: int * int is integral: 1

    std::cout << "int + double result type: " << addResultTypeName<int, double>() << "\n";
    // Expected: int + double result type: floating-point

    std::cout << "int + int result type: " << addResultTypeName<int, int>() << "\n";
    // Expected: int + int result type: integral

    std::cout << "\n===== Demo Complete =====\n";

    return 0;
}