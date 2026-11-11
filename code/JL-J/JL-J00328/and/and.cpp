#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,sum,ans,a[N],v[N],in[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];in[i]=1;
        for(int j=0;j<=30;j++)if(a[i]&(1<<j))v[j]++;
    }
    sum=n;ans=(1<<30)-1;
    for(int p=30;p>=0;p--){
        if(v[p]>=m&&v[p]<sum){
            for(int i=1;i<=n;i++)if(in[i]&&(a[i]&(1<<p))==0)in[i]=0,sum--;
            for(int j=0;j<=30;j++)v[j]=0;
            for(int i=1;i<=n;i++)if(in[i])for(int j=0;j<=30;j++)if(a[i]&(1<<j))v[j]++;
        }
        if(sum==m)break;
    }
    for(int i=1;i<=n;i++)if(in[i])ans=ans&a[i];
    cout<<ans;
    return 0;
}
