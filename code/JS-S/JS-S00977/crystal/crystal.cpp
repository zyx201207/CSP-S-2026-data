#include<bits/stdc++.h>
//#define int long long
using namespace std;
int z[500005],x[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n,m,ans=0;
bool checkA=0,checkB=0;
int tempB;
cin>>n>>m;
cin>>z[0]>>z[1];
tempB=z[1]-z[0];
for(int i=2;i<n;i++)//shuru
{
    cin>>z[i];
    if(z[i]-z[i-1]!=tempB)
        checkB=1;
}
if(checkB==0)//tepan13~18
{
    int ma=1;
    for(int i=1;i<m+5;i++)
    {
        int d=pow(2,i);
        if(m-d*tempB>0&&ma+2<=n)
        {
            m-=d*tempB;
            ma+=2;
        }else
        {
            d/=2;
            if(m-d*tempB>0)
             ma++;
            cout<<ma;
            return 0;
        }
    }
cout<<ma;
return 0;
}
sort(z,z+n);
for(int i=1;i<n;i++)//qianzhuicha
{
    x[i]=z[i]-z[i-1];
}
z[0]=0;
for(int i=1;i<n;i++)//qianzhuihe
{
    z[i]=z[i-1]+x[i];
}
for(int i=1;i<n;i++)//qianzhuihe
{
    x[i]=x[i-1]+z[i];

}
int cnt=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
           cnt=z[j]*(j-i)-(x[j-1]-x[i]);
           if(cnt<=m)
           {
               ans=max(ans,j-i+1);
           }else if(cnt>m)
           {
               i++;
               if(j==i)
                j++;
               if(j<i)
                j+=2;
           }
    }

}
cout<<ans;
}
