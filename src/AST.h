#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
// 所有 AST 的基类
class BaseAST {
 public:
  virtual ~BaseAST() = default;
  virtual void Dump() const = 0;
};

// CompUnit 
class CompUnitAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> func_def;

  void Dump() const override {
    func_def->Dump();
  }
};

// FuncDef 
class FuncDefAST : public BaseAST {
 public:
  unique_ptr<BaseAST> func_type;
  string ident;
  unique_ptr<BaseAST> block;

void Dump() const override 
       {
            std::cout << "fun ";
            std::cout<<"@"<<ident<<"(): ";
            func_type->Dump();
            block->Dump();
        }
};

// FuncType
class FuncTypeAST:public BaseAST{
    public:
    unique_ptr<string>type;

void Dump() const override
        {
            cout<<"i32"<<" ";
        }
};

//block
class BlockAST:public BaseAST{
    public:
    unique_ptr<BaseAST> stmt;

    void Dump() const override{
        cout<<" {\n"<<"%entry:\n";
        stmt->Dump();
        cout<<"}\n";
    }
};

//Stmt
class StmtAST:public BaseAST{
    public:
    int number;

    void Dump() const override{
        cout<<"ret "<<number<<"\n";
    }
};