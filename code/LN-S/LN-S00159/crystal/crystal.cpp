#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long pre[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
    cin>>a[i];

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int l=1,r=1;
    int ans=0;
    while(l<=r)
    {
        if(r>n)
            break;
        if(l==r&&r==n)
            ans=max(1,ans);
       long long len=r-l+1;
        long long now=pre[r]-pre[l-1];
        long long targ=a[r]*len;
        //cout<<l<<" "<<r<<" "<<len<<" "<<now<<" "<<targ<<" "<<ans<<"\n";
        if(now+m>=targ)
        {
            if(len>ans)
                ans=len;
            //ans=max(ans,len);
            r++;
        }
        else{
            l++;
        }
    }
    cout<<ans;

}
