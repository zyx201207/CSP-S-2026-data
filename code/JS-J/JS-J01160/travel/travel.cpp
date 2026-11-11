#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)cout<<"0000",exit(0);
    else cout<<'1';
    string t1="",t2="";
    for(int i=0;i<b.size()-1;++i)t1+=b[i],t2+=d[i];
    if(t1!=t2)cout<<'0';
    else cout<<'1';
    if(t1==t2)
        if(b[2]<='C'&&d[2]>='D')cout<<'0';
        else if(d[2]<='C'&&b[2]>='D')cout<<'0';
        else
        {
            cout<<'1';
            if(abs(b[2]-d[2])==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')cout<<'1';
            else cout<<'0';
            f=true;
        }
    else cout<<'0';
    if(!f)cout<<'0';
}
