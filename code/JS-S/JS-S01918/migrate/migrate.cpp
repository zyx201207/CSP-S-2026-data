#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2000005],f[2000005],f2[2000005];
int n,d,a[2000005];
int lst[2000005],lst1[2000005],cnt[2000005];
void solve(){

    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[1]=1,f[1]=0;
    for(int i=1;i<=n;i++){
        lst[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
        if(lst[i]==i)lst[i]=0;
        lst1[i]=lst[i]+1;
        if(lst[i]==0||lst1[i]==i)lst1[i]=0;
        cnt[i]=i-lst[i];
        if(lst[i]==0)cnt[i]=0;
        else if(lst1[i]==0)cnt[i]=1;
    }
    for(int i=2;i<=n;i++){
        int lt=lst[i],lt1=lst1[i],c=cnt[i];
        int l=lst[lt1],l1=l+1,ct=lst[lt1+1]-l;
        // cout<<"***"<<i<<": "<<lt<<" "<<lt1<<" "<<l<<" "<<l1<<endl;
        if(lt==0)dp[i]=1;
        else if(lt1==0)dp[i]=dp[lt]+1;
        else if(l==lt)dp[i]=dp[lt]-1+c+1;
        else dp[i]=dp[lt]-dp[lt1]+1+c+1;

        if(l==lt||l==0||ct==0||lt1==0)f[i]=0;
        else if(lst[l1]==l)f[i]=(dp[l]-1+ct);
        else f[i]=(dp[l]-dp[l1]+1+ct);
        
        if(lt==0)f2[i]=0;
        else if(lt1==0||l==lt)f2[i]=f2[lt];
        else if(f2[lt]&&lst1[lt]>=l)f2[i]=f2[lt]-f2[lt1]-f[lt]+f[lt1]+f[i];
        else f2[i]=f2[lt]-f2[lt1]+f[lt1]+f[i];//+f[lt]-f[lt1];
    }
    // cout<<"lst:"<<endl;
    // for(int i=1;i<=n;i++)cout<<lst[i]<<" ";
    // cout<<endl;
    // cout<<"lst1:"<<endl;
    // for(int i=1;i<=n;i++)cout<<lst1[i]<<" ";
    // cout<<endl;
    // cout<<"cnt:"<<endl;
    // for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
    // cout<<endl;
    // cout<<"dp:"<<endl;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // for(int i=1;i<=n;i++)if(dp[i]<0){cout<<"ERR:dp "<<i<<endl;exit(0);}
    // // cout<<endl;
    // // cout<<"f:"<<endl;
    // for(int i=1;i<=n;i++)if(f[i]<0){cout<<"ERR:f "<<i<<endl;exit(0);}//cout<<f[i]<<" ";
    // cout<<endl;
    // cout<<"f2:"<<endl;
    // for(int i=1;i<=n;i++)cout<<f2[i]<<" ";
    // cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)ans+=f2[i];
    cout<<ans<<'\n';
}
signed main(){
    // freopen("test.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;cin>>T;
    while(T--)solve();
}