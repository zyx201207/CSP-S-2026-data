#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t;
int n,d;
int x[4000000];
int dp[4000000];
//int cnt[4000000];
//int cntt[4000000];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int tt=0;tt<t;tt++){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        dp[0]=0;

        int al=0;
        for(int i=1;i<n;i++){
            int minl=4000000;
            int l=0,r=i-1;
            while(r-l>1){
                int mid=(l+r)/2;
                //cout<<x[i]-x[mid]<<'\n';
                if(x[i]-x[mid]>d){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            int a=r;
            if(x[i]-x[l]<=d)a=l;

            dp[i]=dp[a]+1;
            // l=a;r=i;
            // while(l-r>=1){
            //     int mid=(l+r)/2;
            //     if(dp[mid]==dp[a]){
            //         l=mid;
            //     }else{
            //         r=mid;
            //     }
            // }
            // int a2=l;
            if(dp[a+1]==dp[a])al++;
            //cout<<a<<' '<<i<<'\n';
            //cnt[i]=cntt[a2]-(a==0?0:cntt[a-1]);
            //cntt[i]=cntt[i-1]+cnt[i];

            for(int j=i-1;j>=0;j--){
                if(x[i]-x[j]>d)break;
                if(dp[j]<minl)minl=dp[j];
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<' ';
        // }
        cout<<al<<'\n';
    }
}