#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,sum;
const int N=2e5+5;
int a[N];
char c[N];
int l[27];
string s="";
bool hw(string s)
{
    int l=s.size();
    for(int i=0;i<=l/2;i++)
    {
        int j=l-i-1;
        if(s[i]!=s[j])
            return 0;
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s=s+c[i];
        }
    }
    if(hw(s))
        cout<<0;
    else
        cout<<1;
    return 0;
}
