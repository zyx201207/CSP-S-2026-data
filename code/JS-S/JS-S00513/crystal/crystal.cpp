#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long M=1e13;
long long n,m,ans=1;
long long a[N],mi=M,s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],mi=min(mi,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) a[i]-=mi,s[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
    {
        long long cnt=0,k=i;
        while(cnt<=m&&k<=n)
        {
            if(cnt+s[k]*(k-i)>m){k++;break;}
            cnt+=s[k]*(k-i);
            //cout<<s[k]<<" "<<k-i+1<<" "<<cnt<<" "<<endl;
            k++;
        }
        ans=max(k-i-1,ans);
        if(ans==n)
        {
            cout<<n;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
