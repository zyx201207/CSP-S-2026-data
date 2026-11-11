#include<bits/stdc++.h>
using namespace std;
bool check1(string n,string m)
{
    int num1=(n[0]-'0')*10+(n[1]-'0');
    int num2=(m[0]-'0')*10+(m[1]-'0');
    if(num1==num2) return 1;
    return 0;
}
bool check2(string n,string m)
{
    char a=n[2],b=m[2];
    if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')) return 1;
    if((a=='D' || a=='F') && (b=='D' || b=='F')) return 1;
    return 0;
}
bool check3(string n,string m)
{
    char a=n[2],b=m[2];
    if(a=='A' && b=='B') return 1;
    if(a=='B' && (b=='A' || b=='C')) return 1;
    if(a=='C' && b=='B') return 1;
    if(a=='D' && b=='F') return 1;
    if(a=='F' && b=='D') return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag1=check1(b,d),flag2=check2(b,d),flag3=check3(b,d);
    if(a==c) cout<<1;
    else cout<<0;
    if(a==c && flag1) cout<<1;
    else cout<<0;
    if(a==c && flag1 && flag2) cout<<1;
    else cout<<0;
    if(a==c && flag1 && flag2 && flag3) cout<<1;
    else cout<<0;
    return 0;
}
