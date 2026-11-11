#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int ans[N];
bool x=true,z=true;
signed main()
{
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  cin>>a[i];
  if(a[i]!=i) x=false;
  }
  int t=a[2]-a[1];
  for(int i=2;i<=n;i++)
  {
      if(a[i]-a[i-1]!=a[i+1]-a[i]) z=false;
  }

  if(x)
  {
      int maxn=0,tot=0;
      if(n%2==1)
      {
      while(m-tot*(tot+1)>=0&&tot<=n)
      {
          tot++;
          if(m-tot*(tot+1)>=0)
          {
              maxn=m-tot*(tot+1)+1;
          }
          else break;
      }
      cout<<maxn;
      return 0;
      }
      else{
        while(m-tot*(tot+1)>=0&&tot<=n)
        {
            tot++;
            if(m-tot*(tot+1)>=0)
            {
                maxn=m-tot*(tot+1)+1;
            }
            else {
                m-=(tot-1)*tot;
                if(m>=a[n]-a[n/2+1]){
                    maxn++;
                }
                break;
            }
        }
      }
  }
  if(n<=5000)
  {
  int maxn=-1e9;
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
  {int tnt=1;
   int tar=a[i],sum=0,mn=m;
   bool flag=true;
   for(int j=1;j<=n;j++)
   {
    int tot=a[j];
    if(tot>tar)
    {
        break;
    }
    else if(tot<=tar){
    int mnmn=tar-tot;
    ans[tnt]=mnmn;
    tnt++;
//    printf("(%d,%d):m=%d,cha=%d,mnmn=%d\n",i,j,tnt,ans[tnt-1],mnmn);
   }
   }
   sort(ans+1,ans+tnt);
   for(int j=1;j<=tnt-1;j++){
       int u=ans[j];
       if(mn>=u)
       {
           mn-=u;
           sum++;
       }
       else if(mn<u)
       {
           flag=!flag;
       }
   }
 //  printf("sum=%d,i=%d\n",sum,i);
   maxn=max(sum,maxn);
   memset(ans,0,sizeof(ans));
  }
  cout<<maxn;
  return 0;
  }
  return 0;
}
