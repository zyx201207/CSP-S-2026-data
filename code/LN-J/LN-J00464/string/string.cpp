#include<bits/stdc++.h>
using namespace std;
struct st
{
    int k;
    char c;
}a[3000000];
int tot=0;
int n;
vector<char>s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    s.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].k>>a[i].c;
        for(int j=0;j<a[i].k;j++)
        {
            s.push_back(a[i].c);
            tot++;
        }
    }
    if(n==1)
    {
        cout<<0<<"\n";
        return 0;
    }
    if(n==2)
    {
        if(a[0].c==a[1].c)
        {
            cout<<0;
        }
        else if(a[0].k<a[1].k)
        {
            cout<<a[0].k;
        }
        else
        {
            cout<<a[1].k;
        }
        return 0;
    }
    for(int i=0;i<tot;i++)
    {
        if(s[i]!=s[tot-1-i])
        {
            cout<<tot-max(a[1].k,a[n].k);
            return 0;
        }
    }
    cout<<0;
    return 0;
}
