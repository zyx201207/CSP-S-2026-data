#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],zd,zzd=-1;
string zejz(int x)
{
    string t="";
    while(x!=0)
    {
        t+=x%2-'0';
        x/=2;
    }
    reverse(t.begin(),t.end());
    return t;
}
int zsjz(string x)
{
    int t=0,j=0,i=0;
    while(!x.empty())
    {
        t+=pow(2,j)*x[i];
        i++,j++;
    }
    return t;
}
int pd(int x)
{
    string t=zejz(x),r=zejz(zd),zhi="";
    reverse(t.begin(),t.end());
    reverse(r.begin(),r.end());
    while(t.size()<r.size()) t+='0';
    while(t.size()>r.size()) r+='0';
    reverse(t.begin(),t.end());
    reverse(r.begin(),r.end());
    for(int i=0;i<t.size();i++)
    {
        if(t[i]!=r[i]) zhi+='1';
        else zhi+='0';
    }
    zd+=zsjz(zhi);
}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n-m+1;j++)
        {
            for(int o=j+1;o<=j+m;o++)
            {
                zd=a[o];
                pd(a[o]);
            }
            zzd=max(zd,zzd);
        }
    cout<<zzd;
    return 0;
}
