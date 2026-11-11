#include <iostream>
#include <algorithm>
using namespace std;
bool eb(string s , string t){
    if(s[0] == t[0] && s[1] == t[1]) return 1;
    else return 0;
}
bool ep(string s,string t){
    if(!eb(s,t))return 0;
    if(s[0] == t[0] && s[1] == t[1]) return 1;
    else return 0;
}
int es(string s,string t){
    if(!ep(s,t)) return 0;
    if(s[2] <= 'C' && t[2] <= 'C') return 1;
    else if((t[2] > 'C' && t[2] <= 'F') && (s[2] <= 'F' && s[2] > 'C')) return 2;
    else return 0;
}
bool bs(string s,string t){
    if(!es(s,t)) return 0;
    if(es(s,t) == 2 || abs(s[2] - t[2]) == 1) return 1;
    else return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<eb(c1,c2)<<ep(s1,s2)<<es(s1,s2)<<bs(s1,s2);
    return 0;
}
