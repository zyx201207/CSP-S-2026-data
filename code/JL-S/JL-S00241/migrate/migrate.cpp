#include<bits/stdc++.h>
using namespace std;
long long c,t,m,d,a[1000005],ans,b[10005][10005],q;
void dfs(int n,int k,int w){
    if(k == 2){
        b[w][n]++;
    }
    else{
        for(int i = n + 1;i <= m;i++){
            if(abs(a[i] - a[n]) > d || (a[i] < 0 && a[n] >= 0) || (a[i] >= 0 && a[n] < 0)) break;
            dfs(i,k+1,w);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        q = 1e7 + 9;
        ans = 0;
        memset(a,0,sizeof(a));
        cin>>m>>d;
        for(int i = 1;i <= m;i++){
            cin>>a[i];
        }
        for(int i = 1;i <= m - 3;i++){
            dfs(i,0,i);
        }
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= m;j++){
                if(b[i][j] == 2 && abs(j - i) <= q){
                    q = abs(j - i);
                    ans++;
                }
                b[i][j] = 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
