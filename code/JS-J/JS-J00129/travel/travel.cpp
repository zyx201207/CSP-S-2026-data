#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ca,cb;
int sa,sb;
char cha,chb;
string tmp;
stringstream ssa,ssb;
map<char,int> side={{'A',1},{'B',1},{'C',1},{'D',2},{'F',2}};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>ca>>tmp;
    ssa<<tmp;
    cin>>cb>>tmp;
    ssb<<tmp;
    ssa>>sa>>cha;
    ssb>>sb>>chb;
    if(ca!=cb)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(sa!=sb)
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if(side[cha]!=side[chb])
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(!((cha=='A' && chb=='B') || (cha=='B' && chb=='C') || (cha=='B' && chb=='A')
         || (cha=='C' && chb=='B') || (cha=='D' && chb=='F') || (cha=='F' && chb=='D')))
    {
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}
