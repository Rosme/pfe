/* MIT License
 *
 * Copyright (c) 2018 Jean-Sebastien Fauteux, Michel Rioux, Raphaël Massabot
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

#include "utils.hpp"
#include "core/utils.hpp"
#include "syntax/rule.hpp"

TEST_CASE("Testing 1TBS syntax style", "[sample]") {
  std::vector<std::string> argv = {"program_name", "-q"};
  SIFT sift;
  sift.parseArgv(argv.size(), convert(argv).data());
  sift.setupLogging();
   
  // Still need a rule to implement
//   SECTION("All green") {
//     const auto stack = doTestWithFile(pfe, "samples/rules/1TBS.json", "samples/src/brightness_manager_1TBS.cc");
//     REQUIRE(stack.size() == 1);
//     REQUIRE(stack.getMessages().begin()->second.size() == 8);
//   }
}

TEST_CASE("Testing Google syntax style", "[sample]") {

  std::string ruleFilePath = "samples/rules/Google.json";
  std::string sourceFilePath = "samples/src/brightness_manager_Google.cc";


}

TEST_CASE("Testing K&R syntax style", "[sample]") {

  std::string ruleFilePath = "samples/rules/KnR.json";
  std::string sourceFilePath = "samples/src/brightness_manager_KnR.cc";


}

TEST_CASE("Testing Allman syntax style", "[sample]") {

  std::string ruleFilePath = "samples/rules/Allman.json";
  std::string sourceFilePath = "samples/src/brightness_manager_Allman.cc";


}

TEST_CASE("Testing GNU syntax style", "[sample]") {

  std::string ruleFilePath = "samples/rules/GNU.json";
  std::string sourceFilePath = "samples/src/brightness_manager_GNU.cc";

}

TEST_CASE("Testing Whitesmiths syntax style", "[sample]") {

  std::string ruleFilePath = "samples/rules/Whitesmiths.json";
  std::string sourceFilePath = "samples/src/brightness_manager_Whitesmiths.cc";


}
