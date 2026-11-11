#include<bits/stdc++.h>
using namespace std;
const int N=500086;
long long n,m,a[N];
void solveBF(){
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long cnt=0,cost=0;
        for(int j=i;j>=1;j--){
            if(cost+a[i]-a[j]<=m){
                cost+=(a[i]-a[j]);
                cnt++;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}
void solvea(){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cnt+=i;
        if(cnt>m){
            cout<<min(n,i-1)<<endl;
            return;
        }
    }
}
void solveb(){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cnt+=i*(a[2]-a[1]);
        if(cnt>m){
            cout<<min(n,i-1)<<endl;
            return;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    bool flaga=1,flagb=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) flaga=0;
        if(i>=3)
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flagb=0;
    }
    if(flaga) solvea();
    else if(flagb) solveb();
    else solveBF();
    return 0;
}