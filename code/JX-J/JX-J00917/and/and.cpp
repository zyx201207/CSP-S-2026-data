#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
void dfs(int d,int sum,int j){
    if(d==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=j+1;i<=n;i++){
        if(d==1) sum=a[i];
        dfs(d+1,(sum&a[i]),i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int ma=0,s=a[1];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        s&=a[i];
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<ans;
    }else if(m==1){
        cout<<ma;
    }else if(m==n){
        cout<<s;
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }else cout<<0;
    return 0;
}
