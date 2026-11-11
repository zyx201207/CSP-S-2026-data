#include<bits/stdc++.h>
using namespace std;
int ans=0;
int m,n;
long long a[200005];
void f(int dep,int i,int cnt){
    if(i==n){
        ans=max(ans,cnt);
        return;
    }
    if(dep>m) return;
    if(i==0){
        f(dep+1,i,cnt);
        f(dep+1,i+1,a[dep]);
    }else{
        f(dep+1,i,cnt);
        f(dep+1,i+1,cnt&a[dep]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>a[i];
    f(1,0,0);
    cout<<ans<<'\n';
    return 0;
}
