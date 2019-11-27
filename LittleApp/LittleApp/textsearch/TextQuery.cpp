#include "TextQuery.h"
#include <fstream>
#include<sstream> 

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1) ? word : word + ending;//make_plural(wc, "word ", "s ")当输入中文本中
                                              //word数大于一是在word后加s，为words为word的复数！
}

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs" << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
    {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}

void runQueries()
{

    ifstream file("1.txt");
    TextQuery tq(file);

    while (true)
    {
        cout << "enter word to look for,or q to quit:";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;

    }
}

TextQuery::TextQuery(ifstream& is):
    file(new vector<string>)
{
    string text;
    while (getline(is,text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto& lines = wm[word];
            if (!lines)
            {
                lines.reset(new set <line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}


TextQuery::~TextQuery()
{
}

QueryResult::QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
    sought(s),
    lines(p),
    file(f)
{

}
