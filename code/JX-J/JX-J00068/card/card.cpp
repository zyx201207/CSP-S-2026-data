#include<bits/stdc++.h>
long long s[200005];
int maxx=-1;
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    cin>>s[i];
}
sort(s,s+n);
if(m==1)
{
cout<<s[n-1];
}
if(m==2)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(s[i]&s[j]>=maxx)
                maxx=s[i]&s[j];
        }
    }
}
if(m==3)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
          for(int t=j-1;t>=0;t--)
          {
              if(s[i]&s[j]&s[t]>=maxx)
                maxx=s[i]&s[j]&s[t];
          }
        }
    }
}
if(m==4)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
          for(int t=j-1;t>=0;t--)
          {
              for(int o=t-1;o>=0;o--)
              if(s[i]&s[j]&s[t]&s[o]>=maxx)
                maxx=s[i]&s[j]&s[t]&s[o];
          }
        }
    }
}
cout<<maxx;
return 0;
}
