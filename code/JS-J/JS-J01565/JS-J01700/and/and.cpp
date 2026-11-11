#include<bits/stdc++.h>
using namespace std;
long long ans = INT_MIN;
int n,m;
int a[200005];
void dfs(int i,long long sum,int cnt){
    if(i>n){
        if(cnt==m){
            ans = max(ans,sum);
        }
        return ;
    }
    if(cnt<m){
        if(sum==-1LL){
            dfs(i+1,a[i],cnt+1);
        }else{
            dfs(i+1,sum&a[i],cnt+1);
        }
    }
    dfs(i+1,sum,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int sum = a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }else if(m==1){
        int ma = INT_MIN;
        for(int i=1;i<=n;i++){
            ma = max(ma,a[i]);
        }
        cout<<ma;
        return 0;
    }
    dfs(1,-1,0);
    cout<<ans;
    return 0;
}
