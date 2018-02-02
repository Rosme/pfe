/* MIT License
*
* Copyright (c) 2018 Jean-Sebastien Fauteux, Michel Rioux, Rapha�l Massabot
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "catch.hh"

#include "core/scope.hpp"

TEST_CASE("Scope Children", "[scope]") {

  using namespace Core;
  Scope root(ScopeType::Source);
  //TODO Red Maybe it is best to settle on how scope works before writing those tests
/*

  SECTION("Get All Children") {
    for(int i = 0; i < 10; ++i) {
      root.pushChild(Scope(static_cast<ScopeType>(1u << i)));
    }

    REQUIRE(root.getChildren().size() == 10);
  }

  SECTION("Get Specific Children") {
    for(int i = 0; i < 10; ++i) {
      root.pushChild(Scope(static_cast<ScopeType>(1u << i)));
    }

    REQUIRE(root.getChildrenOfType(Core::ScopeType::Class).size() == 1);
    REQUIRE(root.getChildrenOfType(Core::ScopeType::Variable).size() == 3);
  }

  SECTION("Found No Children") {
    for(int i = 0; i < 5; ++i) {
      root.pushChild(Scope(static_cast<ScopeType>(1u << i)));
    }

    REQUIRE(root.getChildrenOfType(Core::ScopeType::Variable).size() == 0);
  }*/


  SECTION("Enum to String") {
    REQUIRE(to_string(ScopeType::Function) == "Function");
  }

  SECTION("String to Enum") {
    REQUIRE(ScopeType_to_enum_class("fuNcTiOn") == ScopeType::Function);
  }
}
