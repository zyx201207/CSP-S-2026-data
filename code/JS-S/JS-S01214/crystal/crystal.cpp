#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;
int n,ans;
long long a[N];
long long m,dp[N],c[N];
long long yy[N];
/*int cry(int x){
    long long cnt=0;
    int res=1;
    for(int i=x-1;i>0;i--){
        cnt+=a[x]-a[i];
        if(cnt>m)break;
        res++;
    }
    cout<<cnt<<' '<<res<<'\n';
    return res;
}*/

main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
        dp[i]=dp[i-1]+c[i];
    }
    //for(int i=1;i<=n;i++)cout<<c[i]<<' ';
    //cout<<endl;
    //for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    //cout<<endl;
    int last=0;
    for(int i=1;i<=n;i++){
        yy[i]=yy[i-1]+c[i]*(i-1);
        //cout<<yy[i]<<' ';
        while(yy[i]-yy[last]>m)last++;
        ans=max(ans,i-last);
    }
    cout<<ans;
    //for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    //cout<<endl;

    /*
    long long cnt=0;
    int res=1;
    for(int i=2;i<=n;i++){
        //if(a[i]-a[i-1]>m){cnt=a[i]-a[i+1],res=1;continue;}
        cnt+=(a[i]-a[i-1])*res;
        ++res;
        if((a[i]-a[i-1])*2>m){
            cnt=0;
            res=1;
            continue;
        }
        while(cnt>m){
            //cout<<cnt<<' '<<res<<endl;
            cnt-=dp[i]-dp[i-res+1];
            --res;

        }
        ans=max(ans,res);
        //cout<<cnt<<' '<<res<<'\n';
    }
    cout<<ans;
    */

}
