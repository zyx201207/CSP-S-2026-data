#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N];
long long n;
long long m;
long long ans=-1;
bool cmp(long long a,long long b){
    return a>b;
}
void dfs(int dep,int cnt,int sum){
    if(dep==n+1){
        if(cnt==m){
            if(sum>=ans){
                ans=sum;
            }
        }
        return;
    }
    dfs(dep+1,cnt+1,(sum&a[dep]));
    dfs(dep+1,cnt,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    dfs(1,0,a[1]);
    cout<<ans;
    return 0;
}
