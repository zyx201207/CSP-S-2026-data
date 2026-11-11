#include<bits/stdc++.h>
using namespace std;
int a[130];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    a['A']=2;
    a['B']=3;
    a['C']=4;
    a['D']=6;
    a['F']=7;
    string q,w,e,r;
    cin>>q>>w>>e>>r;
    if(q!=e)cout<<0;
    else cout<<1;
    if(q==e&&w[0]==r[0]&&w[1]==r[1])cout<<1;
    else cout<<0;
    if(q==e&&w[0]==r[0]&&w[1]==r[1]&&('A'<=w[2]&&w[2]<='C'&&'A'<=r[2]&&r[2]<='C')||((w[2]=='D'||w[2]=='F')&&(r[2]=='D'||r[2]=='F')))cout<<1;
    else cout<<0;
    if(q==e&&w[0]==r[0]&&w[1]==r[1]&&abs(a[w[2]]-a[r[2]])==1)cout<<1;
    else cout<<0;
}
