#include<bits/stdc++.h>
#define maxn 1000
#define int long long
using namespace std;
int c,t;
int ans=0;
int x[maxn];
int n,d;
int num;
int sum;
void dfs(int nn,int now,int to){
    if(nn==sum){
        if(now==to){
            ans++;
        }
        return;
    }
    for(int i=now;i<=to;i++){
        if(x[i]-x[now]<=d){
            dfs(nn+1,i,to);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        num=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=0;
                sum=(x[j]-x[i])/d;
                if((x[j]-x[i])%d!=0){
                    sum++;
                }
                dfs(0,i,j);
                if(ans==2){
                    num++;
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}//8分暴力
