#pragma once
#include "../common/head.h"

using line_no = vector<string>::size_type;

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f);

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

class TextQuery
{
public:

    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    ~TextQuery();

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

