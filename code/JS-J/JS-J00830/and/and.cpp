#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,maxn=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>=maxn) maxn=a[i];
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                int t=a[i]&a[j];
                if(t>=maxn) maxn=t;
            }
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}
