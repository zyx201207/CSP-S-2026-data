#include<bits/stdc++.h>
using namespace std;
int n,m,a[210000];
string ejz(int x)
{
    string s="";
    while(x!=0)
    {
        s+=char(x%2+'0');
        x=x/2;
    }
    return s;
}
int aw(int n,int m)
{
    string x=ejz(n),y=ejz(m),s="";
    int h=0;
    for(int i=0;i<max(x.size(),y.size());i++)
    {
        if(x[i]==y[i])
            s+='1';
        else
            s+='0';
    }
    for(int i=s.size()-1;i>=0;i--)
        h+=(s[i]-'0')*pow(2,i);
    return h;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int s=a[n];
    for(int i=n-1;i>n-m;i--)
        s=aw(s,a[i]);
    cout<<s;
    return 0;
}
