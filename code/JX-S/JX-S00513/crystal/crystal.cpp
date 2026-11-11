#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long num[500005],qj[500005];
long long ans=0;
bool check(long long dat)
{
    for(int i=dat;i<=n;i++)
    {
        long long cost=qj[i]-qj[i-dat+1]-(num[i]-num[i-dat+1])*(i-dat);
        if(cost<=m)
            return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
        cin>>num[i];
   sort(num+1,num+1+n);
   for(int i=1;i<=n;i++)
   {
       qj[i]=qj[i-1];
       qj[i]+=(num[i]-num[i-1])*(i-1);
   }
  long long l=1,r=n;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
