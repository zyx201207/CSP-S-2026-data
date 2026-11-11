#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
    return a>b;
}
long long n,m,a[2000005];long long ans=0;
void dfs(long long x,long long cnt,long long num){
    if(num==m){
        ans=max(ans,cnt);
        return;
    }
    if(x>n) return;
    dfs(x+1,cnt,num);
    dfs(x+1,cnt&a[x],num+1);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);

    if(m==1) ans=a[1];
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    ans=max(ans,(long long)a[i]&a[j]);
            }
        }
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            ans=pow(2,30)-1;
            for(int j=1;j<=n;j++){
                if(j!=i) ans&=a[j];
            }
        }
    }
    else{
        dfs(1,pow(2,30)-1,0);
    }
    cout<<ans;
    return 0;
}
