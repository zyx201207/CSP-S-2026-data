#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
inline bool sameq(char q1,char q2)
{
    if(q1>q2) swap(q1,q2);
    if(q1=='D'&&q2=='F'||q1=='A'&&q2=='B'||q1=='A'&&q2=='C'||q1=='B'&&q2=='C') return true;
    return false;
}
inline bool xl(char q1,char q2)
{
    if(q1>q2) swap(q1,q2);
    if(q1+1==q2&&q1!='C') return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int p1=stoi(s1.substr(0,2)),p2=stoi(s2.substr(0,2));
    char q1=s1[2],q2=s2[2];
    cout<<(c1==c2?'1':'0');
    cout<<(c1==c2&&p1==p2?'1':'0');
    cout<<(c1==c2&&p1==p2&&sameq(q1,q2)?'1':'0');
    cout<<(c1==c2&&p1==p2&&xl(q1,q2)?'1':'0');
    return 0;
}
