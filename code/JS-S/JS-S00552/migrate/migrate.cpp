#include<bits/stdc++.h>
using namespace std;
int c,t,n,l,r1,r2,ans,nxt[2000005];
long long d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
 //   freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==114514) cout<<"it's been a long day~\n";
    if(c==1919810) cout<<"without you my friend~\n";
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        l=r1=r2=ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(a[j+1]-a[i]<=d&&j<=n) j++;
            nxt[i]=j;
        }
        for(int i=1;i+3<=n;i++)
        {
            if(nxt[i]==i+1)
            {
                l++;
                continue;
            }
            int k=i,r=0;
            while(nxt[k]!=nxt[nxt[k]-1]&&nxt[nxt[k]-1]!=nxt[nxt[k]-2]&&nxt[k])
            {
                r2+=nxt[nxt[k]-1]-nxt[k];
                k=nxt[k];
            }
            int rrr=nxt[k];
            while(nxt[rrr]==rrr+1&&r2)
            {
                rrr++;
                r1++;
            }
            ans+=(r1+r2);cout<<i<<" "<<l<<" "<<r1<<" "<<r2<<endl;
            l=r1=r2=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
