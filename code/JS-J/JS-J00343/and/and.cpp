#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,f[N][31],dp[35],a[N],mx,sum;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=a[i],j=0;
        while(t){
            if(t%2) f[i][j]=1;
            t/=2,j++;
        }
        mx=max(mx,j);
    }
    for(int i=0;i<mx;i++){
        for(int j=1;j<=n;j++){
            if(f[j][i]) dp[i]++;
        }
    }
    int s,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(f[i][j]) s=j;
        }
        for(int j=0;j<=s;j++){
            if(!f[i][j]) flag=1;
        }
    }
    if(!flag){
        for(int j=0;j<mx;j++){
            if(dp[j]<m) break;
            int b=pow(2,j);
            sum+=b;
        }
        cout<<sum;
    }
    else if(n<=2000){
        if(m==n){
            sum=a[1];
            for(int i=2;i<=n;i++) sum&=a[i];
            cout<<sum;
            return 0;
        }
        if(m==1){
            for(int i=1;i<=n;i++) sum=max(sum,a[i]);
            cout<<sum;
            return 0;
        }
        if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    sum=max(sum,a[i]&a[j]);
                }
            }
            cout<<sum;
            return 0;
        }
        for(int i=0;i<mx;i++){
            if(dp[i]<m) break;
            int b=pow(2,i);
            sum+=b;
        }
        cout<<sum;
        return 0;
    }
    else {
        for(int i=0;i<mx;i++){
            if(dp[i]<m) break;
            int b=pow(2,i);
            sum+=b;
        }
        cout<<sum;
    }
    return 0;
}
