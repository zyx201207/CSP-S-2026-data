#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
ll a[N],g[N][N];
ll c,t,n,d;
inline ll estance(int l,int r){
    ll res=0;
    ll sum=0;
    for(int i=l;i<=r;i++){
        if(a[i]-a[i-1]>d) return -1;
        if(sum+a[i]>d){
            sum=a[i];
            res++;
        }
        sum+=a[i];
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int len=3;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=n-len+1;
                g[i][j]=estance(i,j);
            }
        }

    }
    return 0;
}
