#include<bits/stdc++.h>
using namespace std;
int a[200005][32];
int b[200005];
int ans[32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i){
        long long a1;cin>>a1;
        int j=0;
        while(a1>0){
            a[i][++j]=a1%2;
            a1/=2;
        }
    }
    for(int i=1;i<=n;++i) b[i]=1;
    for(int i=30;i>=1;--i){
        int num=0;
        for(int j=1;j<=n;++j){
            if(b[j]&&a[j][i]==1) num++;
        }
        if(num<m) continue;
        for(int j=1;j<=n;++j){
            if(a[j][i]==0) b[j]=0;
        }
    }
    int cnt=0;
    for(int i=1;i<=30;++i) ans[i]=1;
    for(int i=1;i<=n;++i){
        if(!b[i]) continue;
        for(int j=1;j<=30;++j){
            if(a[i][j]==0) ans[j]=0;
        }
        cnt++;
        if(cnt>=m) break;
    }
    long long ans1=0;
    for(int i=1;i<=30;++i){
        ans1+=ans[i]*pow(2,i-1);
    }
    cout<<ans1;
    return 0;
}
