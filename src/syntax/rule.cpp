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

#include "rule.hpp"
#include "../core/utils.hpp"

namespace Syntax {
  
  std::vector<Rule> readRules(const std::string& rulesFile) {
    std::vector<Rule> rules;
    
    auto json = Core::readJsonFile(rulesFile);
    
    if(json["rules"].is_array())
    {
      auto jsonRules = json["rules"].array();
      
      for(const auto& jsonRule : jsonRules)
      {
        Rule rule(Core::ScopeType_to_enum_class(jsonRule["appliedTo"].get<std::string>()));
        rules.push_back(rule);
      }
    }
    
    return rules;
  }
  
  Rule::Rule(Core::ScopeType applyTo)
    : m_applyTo(applyTo)
  {
  }
  
}
