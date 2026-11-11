#include<bits/stdc++.h>
using namespace std;
int a,b,s[100001],cnt=1,cnt1=1,c;
int map(int x,int y)
{
	return x<y;}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
    cin>>s[i];
    }
    sort(s+1,s+1+a,map);
    for(int i=2;i<=a;i++)
    {     cnt=1;
          c=b;
      for(int j=i-1;j>=0;j--)
      {if(s[j]+b>=s[i])
       {cnt++;
       c=c-(b-s[j]);
      }
      else
        {
        if(cnt>cnt1)
           { cnt1=cnt;}
        break;}
    }
   }cout<<cnt1;
    return 0;}
