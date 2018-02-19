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

#pragma once

#include <map>
#include <functional>

#include "syntax_analyser.hpp"
#include "rule.hpp"

#include "../core/scope.hpp"
#include "../core/message_stack.hpp"

namespace Syntax {
  
  class CPPSyntaxAnalyser : public SyntaxAnalyser {
  public:
    CPPSyntaxAnalyser();
    virtual ~CPPSyntaxAnalyser();
    
    void registerRuleWork(std::map<Syntax::RuleType, std::function<void(Syntax::Rule&, Core::Scope&, Core::MessageStack&)>>& work);
    
    void RuleUnknown(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleNoAuto(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleNoDefine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleNoMacroFunctions(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleStartWithX(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleEndWithX(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleMaxCharactersPerLine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleCurlyBracketsOpenSameLine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleCurlyBracketsOpenSeperateLine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleCurlyBracketsCloseSameLine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleCurlyBracketsCloseSeperateLine(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleAlwaysHaveCurlyBrackets(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleNoConstCast(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleStartWithLowerCase(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleStartWithUpperCase(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    void RuleNameMaxCharacter(Syntax::Rule& rule, Core::Scope& rootScope, Core::MessageStack& messageStack);
    
    bool IsScopeUsingCurlyBrackets(Core::Scope& scope);
    bool IsOpeningCurlyBracketSeparateLine(Core::Scope& scope);
    bool IsClosingCurlyBracketSeparateLine(Core::Scope& scope);
  };
  
}
