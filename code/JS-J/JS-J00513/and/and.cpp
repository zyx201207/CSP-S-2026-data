#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool f[200010];
int s[200020];
int ans;
void dfs(int deep,int sum,int far){
    if(deep==m){
        ans=max(ans,sum);
        return;
    }else{
        for(int i=1;i<=n;i++){
            if(f[i]==0&&a[i]>sum){
                f[i]=1;
                sum&=a[i];
                dfs(deep+1,sum,i+1);
                f[i]=0;
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        s[0]=a[i];
        dfs(1,a[i],i+1);
        f[i]=0;
    }
    cout<<ans;
    return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/