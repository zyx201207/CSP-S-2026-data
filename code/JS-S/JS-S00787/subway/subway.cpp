#include<bits/stdc++.h>
using namespace std;
int c;
long long n,m,d,p,t[500005],ans;
long long a[10005][10005];
bool f[10005][10005];
void dfs(int no,int t0,long long ta){
    if(no==t0){
        ans=min(ans,ta);
        return ;
    }
    ta+=t[no];
    for(int i=1;;i+=2){
        if(a[no][i]==0){
            return ;
        }
        if(!f[no][i]){
            dfs(a[no][i],t0,ta+a[no][i+1]);
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=1;j<=2*num;j+=2){
            cin>>a[i][j]>>a[i][j+1];
        }
    }
    while(p--){
        int s,t0;
        ans=10000005;
        cin>>s>>t0;
        dfs(s,t0,0);
        cout<<ans<<endl;
    }
    return 0;
}


