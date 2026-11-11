#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
int b[N];
int a[N][40];
bool vis[40];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin >>n>>m;
    for(int i=1;i<=n;i++)cin >>b[i];
    sort(b+1,b+1+n,greater<int>());
    for(int i=1;i<=n;i++){
        int s=(1<<29);
        for(int j=29;j>=0;j--){
            a[i][j]=(b[i]>=s);
            if(b[i]>=s)b[i]-=s;
            s/=2;
        }
    }
    for(int i=0;i<=29;i++)vis[i]=1;
    // int sum=0;
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i])cnt++;
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==0){
                    for(int k=0;k<=29;k++)a[j][k]=0;
                }
            }
        }else vis[i]=0;
    }
    int ans=0,cnt=1;
    for(int k=0;k<=29;k++){
        // cout<<vis[k];
        if(vis[k])ans+=cnt;
        cnt*=2;
    }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/