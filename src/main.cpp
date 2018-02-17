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


#include <iostream>
#include <muflihun/easylogging++.h>

#include "pfe.hpp"
#include "core/utils.hpp"
#include "core/file.hpp"
#include "syntax/rule.hpp"

#include <regex>
#include <chrono>
INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {
  START_EASYLOGGINGPP(argc, argv);
  
  std::chrono::time_point<std::chrono::system_clock> before = std::chrono::system_clock::now();
  
  PFE pfe;
  pfe.parseArgv(argc, argv);
  pfe.setupLogging();
  pfe.setupRules(pfe.getRuleFileName());
  pfe.registerRuleWork();
  pfe.readPath(pfe.getPathToParse());
  pfe.extractScopes();
  pfe.applyRules();
  pfe.outputMessages();

  std::chrono::time_point<std::chrono::system_clock> after = std::chrono::system_clock::now();
  LOG(INFO) << "Ran in " << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count() << "ms";

  std::cin.get();
  return 0;
}
