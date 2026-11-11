#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
int f[N];
void t1(int v,int t){
    if(v==1){
        for(int i=2;i<=n;i++){
            if(a[i]==a[v]) f[v]++;
        }
    }else if(v==n){
        for(int i=n-1;i>=1;i++){
            if(t>=a[v]-a[i]) f[v]++,t-=a[v]-a[i];
        }
    }else{
        for(int i=v-1;i>=1;i--){
            if(a[v]-a[i]<=t) f[v]++,t-=a[v]-a[i];
        }
        for(int i=v+1;i<=n;i++) if(a[i]==a[v]) f[v]++;
    }
    f[v]++;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) t1(i,m);
    sort(f+1,f+n+1);
    cout<<f[n];
    return 0;
}