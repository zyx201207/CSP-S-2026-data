#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000000];
int dfs(int x,int y){
    if(x==y)return 1;
    int f=0;
    for(int i=1;i<=d;i++)
        if(x+i<=y)f+=dfs(x+i,y);
    return f;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        int ans=0;
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n-2;i++){
            for(int j=i+2;j<=n;j++){
                if(dfs(i,j)==2){
                    ans++;
                    cout<<i<<" "<<j;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
