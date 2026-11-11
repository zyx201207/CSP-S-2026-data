#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
inline bool checka(){
    set<char>s;
    s.insert('A');
    s.insert('B');
    s.insert('C');
    if(s.count(s1[2])==s.count(s2[2]))return 1;
    return 0;
}
inline bool checkb(){
    if(abs(s1[2]-s2[2])==1)return 1;
    return 0;
}
int main(){
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&checka())cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&checka()&&checkb())cout<<1;
    else cout<<0;
    cout<<endl;
    return 0;
}