#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],vh[3010],dp[5010],dp1[3010];
void work1(int k){
    for(int i=1;i+k-1<=n;i++){
        int maxv=i+k-1;
        if(dp1[a[maxv]]==0){
            dp1[a[maxv]]++;
            dp[i]=a[maxv];
        }else{
            dp1[a[maxv]]++;
            dp[i]=a[maxv];
            int f=0;
            for(int j=i-1;j>=1;j--){
                if(dp[j]==dp[i])f=1;
                dp1[dp[j]]--;
                dp[j]=0;
                if(f==1)break;
            }
        }
    }
}
void work(){
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        work1(i);
        for(int i=1;i<=n;i++){
            vh[dp[i]]++;
        }
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    work();
    for(int i=1;i<=m;i++){
        cout<<vh[i]<<" ";
    }
    cout<<"\n";
    return 0;
}