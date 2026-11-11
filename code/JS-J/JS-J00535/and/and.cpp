#include<bits/stdc++.h>;
using namespace std;
#define int long long
int n,m,a[2000005],maxn;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i!=j){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        maxn=a[1];
        for(int i=2;i<=n;i++){
            maxn=maxn&a[i];
        }
        cout<<maxn;
        return 0;
    }
    else if(m==3){
        for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
        for(int j=1;j<=n;j++){
            if(i!=j&&j!=k&&i!=k){
                int t=a[i]&a[j];
                maxn=max(maxn,t&a[k]);
            }
        }
        cout<<maxn;
        return 0;
    }
}
