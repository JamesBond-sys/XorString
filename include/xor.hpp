#pragma once

#include <iostream>
#include <array>
#include <algorithm>

namespace Xor {
        template<std::size_t S>
        struct Xor_String {
            std::array<char, S> chars;

            inline auto operator()() {
                std::string str{};
                std::transform(chars.begin(), chars.end(), std::back_inserter(str), [](auto const& c) {
                    return c ^ S;
                });
                return str;
            }

            constexpr Xor_String(const char(&string)[S]) : chars{} {
                auto it = chars.begin();
                for (auto const& c : string) {
                    *it = c ^ S;
                    it++;
                }
            }
        };
}

#define Xor(string) [](){ static auto _ = Xor::Xor_String<sizeof(string)/sizeof(char)>{string}; return _(); }();
