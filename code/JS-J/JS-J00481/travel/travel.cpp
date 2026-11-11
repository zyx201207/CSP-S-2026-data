#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string c1,c2;
    int a1,a2;
    char s1,s2;
    cin>>c1>>a1>>s1>>c2>>a2>>s2;
    if(c1==c2) cout<<1;
    else {cout<<0;cout<<0;cout<<0;cout<<0;return 0;}
    if(a1==a2) cout<<1;
    else {cout<<0;cout<<0;cout<<0;return 0;}
    if(((s1<=(int)'C'&&s2<=(int)'C')||(s1=='D'&&s2=='F'||s1=='F'&&s2=='D'))&&a1==a2) cout<<1;
    else {cout<<0;cout<<0;return 0;}
    if((abs((int)s1-(int)s2)==1&&(s1=='D'&&s2=='F'||s1=='F'&&s2=='D'&&s1!='C'&&s2!='D'||s2!='C'&&s1!='D'))&&(a1==a2)) cout<<1;
    else cout<<0;
    return 0;
}