#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <fstream>
#include <vector>
using namespace std;
class article
{
    string title,content;
public:
    article(string,string);
    article(const article &art);
    friend ostream& operator <<(ostream &,const article &);
    friend istream& operator >>(istream &,article &);
    int getId();
    string getTitle();
    string getContent();
    
};
article::article(string title = "",string content = "") //constructor
{
    this->title = title;
    this->content = content;
}
article::article(const article &art)
{
    this->title = art.title;
    this->content = art.content;
}
ostream& operator <<(ostream &out, const article &ar) //output
{
    out<<"      "<<ar.title<<endl;
    out<<ar.content<<endl;
    return out;
}
istream& operator >>(istream &in, article &ar) //input
{
    string temp;
    getline(in,ar.title);
    ar.content=""; //Read paragraph (read till you meet emptyline)
    getline(in,temp);
    while(temp!="")
    {
        ar.content += temp + "\n";
        getline(in,temp);
    }
    

    return in;
}
string article::getTitle()
{
    return title;
}
string article::getContent()
{
    return content;
}
void load(vector<article> &lista,vector<int> &fav)
{
    ifstream inp("input.txt");
    article x;
    int n,nr;
    inp>>n;
    lista.reserver(n);
    inp.ignore();
    for(int i=0;i<n;i++)
    {
        inp>>x;
        lista.push_back(x);
    }
    while(inp>>nr)
        fav.emplace_back(nr);
    inp.close();
}
void save(vector<article> lista,vector<int> fav)
{
    ofstream out("output.txt");
    out<<lista.size()<<endl;
    for(int i=0;i<lista.size();i++)
    {
        out<<lista[i].getTitle()<<endl;
        out<<lista[i].getContent()<<endl;
    }
    for(int i=0;i<fav.size();i++)
        out<<fav[i]<<" ";
    out.close();
}
int main()
{
    vector<article> lista;
    vector<int> fav;
    load(lista,fav);
    for(int i=0;i<lista.size();i++)
        cout<<lista[i];
    for(int i=0;i<fav.size();i++)
        cout<<fav[i]<<" ";
    save(lista,fav);
    getch();
}