#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000001];
int dfs(int x,int y){
    if(abs(x-y)==1||x==y)return 0;
    int cnt=0;
    if(a[y]-a[x]<m) cnt++;
    for(int i=x+1;i<=y;i++){
        if(a[y]-a[i]>m) continue;
        cnt+=dfs(i,y);
    }
    return cnt;
}
bool is(int x,int y){
    if(dfs(x,y)==2) return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=i+3;j++){
                if(is(i,j)) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
