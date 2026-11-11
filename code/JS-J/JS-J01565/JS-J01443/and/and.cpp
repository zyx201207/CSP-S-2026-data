#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+7;
int a[N],n,m,ans;
void dfs(int all,int num,int i){
    if(i>n){
        if(num==m) ans=max(ans,all);
        return ;
    }
    if(num==0) dfs(a[i],num+1,i+1);
    else dfs(all&a[i],num+1,i+1);
    dfs(all,num,i+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxn=0,sum;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(maxn,a[i]);
        if(i==1) sum=a[i];
        else sum&=a[i];
    }
    if(m==1){
        cout << maxn;
        return 0;
    }
    if(m==n){
        cout << sum;
        return 0;
    }
    dfs(1,0,1);
    cout << ans;
    return 0;
}
