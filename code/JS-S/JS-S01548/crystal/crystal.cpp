#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],c[500005];
int sol_na(int ni){
    int na = 1;
    int ji = a[ni],ne = 0;
    for(int j = ni-1;j>0;j--){
        if(ne+ji-a[j]<=m){
            na++;
            ne+=ji-a[j];
        }
    }return na;
}
void solve_5000(){
    for(int i = n;i>=ans;i--){
        ans = max(ans,sol_na(i));
    }cout<<ans;
    return ;
}
void solve_final(){
    for(int i = 1;i<=n;i++)c[i] = a[i]-a[i-1];
    int l = 1,r = 1,ne = a[1];
    while(l<=r&&r<=n){
        if(ne+c[r+1]*(r-l+1)<=m){
            r++;
            ne+=c[r]*(r-l);
            ans = max(ans,r-l);
        }else{
            l++;
            ne-=a[r]-a[l];
        }
    }cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000)solve_5000();
    else solve_final();
}
