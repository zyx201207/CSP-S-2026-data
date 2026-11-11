#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans=0;
void dfs(int x,int cnt,long long sum){
    if(x>n){
        if(cnt==m){
            ans=max(ans,sum);
        }
        return ;
    }
    if(cnt>m)return;
    dfs(x+1,cnt,sum);
    if(sum==0)
    dfs(x+1,cnt+1,a[x]);
    else
    dfs(x+1,cnt+1,sum&a[x]);
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
    cout<<maxx<<endl;
    }
    else if(m==2){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx<<endl;
    }
    else if(n<=20){
        for(int i=1;i<=n;i++)
        dfs(i,0,0);
        cout<<ans<<endl;
    }
    else {
        sort(a+1,a+1+n,cmp);
        cout<<a[m]<<endl;
    }
    return 0;
}
