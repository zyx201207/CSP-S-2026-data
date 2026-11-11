#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c==cc)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    int a=0,b=0;
    char t,tt;
    for(int i=0;i<2;i++)
    {
        a=a*10+s[i]-'0';
    }
    t=s[2];
    for(int i=0;i<2;i++)
    {
        b=b*10+ss[i]-'0';
    }
    tt=ss[2];
    if(c==cc&&a==b)
    {
    	cout<<1;
	}
    else
    {
        cout<<0;
    }
    if(c==cc&&a==b&&( (t=='A'&&tt=='B') || (t=='A'&&tt=='C') || (t=='B'&&tt=='C') || (t=='B'&&tt=='A') || (t=='C'&&tt=='A') || (t=='C'&&tt=='B') || (t=='D'&&tt=='F') || (t=='F'&&tt=='D') ))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c==cc&&a==b&&( (t=='A'&&tt=='B') || (t=='B'&&tt=='C') || (t=='B'&&tt=='A') || (t=='C'&&tt=='B') || (t=='D'&&tt=='F') || (t=='F'&&tt=='D') ))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
