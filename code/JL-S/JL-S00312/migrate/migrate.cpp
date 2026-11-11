#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
struct node{
    long long zhi;
    bool isone=false;
}dp[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        long long gongcha;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=2){
                if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                    gongcha=0;
                }
                else gongcha=a[i]-a[i-1];
            }
        }
        int suishi=0;
        for(int i=1;i<=n;i++){
            if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                suishi=i;
                break;
            }
        }
        if(d>=a[n]-a[1]){
            cout<<"0"<<'\n';
            continue;
        }
        if(n<=600){
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[j].zhi=0;
                    dp[j].isone=false;
                }
                for(int j=i+1;j<=n;j++){
                    if(a[j]>a[i]+d) break;
                    else{
                        dp[j].zhi=1;
                        dp[j].isone=1;
                    }
                }
                for(int j=1;j<=n;j++){
                    if(dp[j].isone==1) continue;
                    for(int k=j-1;k>=1;k--){
                        if(a[k]<a[j]-d) break;
                        else if(dp[k].isone==1) dp[j].zhi+=dp[k].zhi;
                    }
                }
                for(int j=1;j<=n;j++){
                    if(dp[j].zhi==2&&dp[j].isone==false){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<'\n';
        }
        else if(gongcha){
            if(d<2*gongcha) cout<<"0"<<'\n';
            else{
                if(d>=3*gongcha) cout<<"0"<<'\n';
                else{
                    cout<<n-3<<'\n';
                }
            }
        }
        else if(suishi){
                int cnt=0;
            for(int i=1;i<suishi;i++){
                for(int j=suishi+1;j<=n;j++){
                    if(a[j]-a[i]>d) cnt++;
                }
            }
            for(int i=1;i<suishi;i++){
                for(int j=1;j<suishi;j++){
                    dp[j].zhi=0;
                    dp[j].isone=false;
                }
                for(int j=i+1;j<suishi;j++){
                    if(a[j]>a[i]+d) break;
                    else{
                        dp[j].zhi=1;
                        dp[j].isone=1;
                    }
                }
                for(int j=1;j<suishi;j++){
                    if(dp[j].isone==1) continue;
                    for(int k=j-1;k>=1;k--){
                        if(a[k]<a[j]-d) break;
                        else if(dp[k].isone==1) dp[j].zhi+=dp[k].zhi;
                    }
                }
                for(int j=1;j<suishi;j++){
                    if(dp[j].zhi==2&&dp[j].isone==false){
                        cnt++;
                    }
                }
            }
            for(int i=suishi;i<=n;i++){
                for(int j=suishi;j<=n;j++){
                    dp[j].zhi=0;
                    dp[j].isone=false;
                }
                for(int j=i+1;j<=n;j++){
                    if(a[j]>a[i]+d) break;
                    else{
                        dp[j].zhi=1;
                        dp[j].isone=1;
                    }
                }
                for(int j=suishi;j<=n;j++){
                    if(dp[j].isone==1) continue;
                    for(int k=j-1;k>=1;k--){
                        if(a[k]<a[j]-d) break;
                        else if(dp[k].isone==1) dp[j].zhi+=dp[k].zhi;
                    }
                }
                for(int j=suishi;j<=n;j++){
                    if(dp[j].zhi==2&&dp[j].isone==false){
                        cnt++;
                    }
                }
            }
        }
    }
    return 0;
}
