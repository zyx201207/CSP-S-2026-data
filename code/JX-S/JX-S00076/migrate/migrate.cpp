#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[2000005];
int ans[305][2];
long long sum=0;
struct st{
    int u,k;
};
void bfs(int x){
    queue<st>q;
    q.push({x,0});
    while(!q.empty()){
        st e=q.front();
        q.pop();
        if(ans[e.u][0]==0){
            ans[e.u][0]=e.k;
            ans[e.u][1]++;
        }
        else if(ans[e.u][0]==e.k){
            ans[e.u][1]++;
        }
        for(int i=e.u+1;i<=n;i++){
            if(a[e.u]>=a[i]-d){
                q.push({i,e.k+1});
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            memset(ans,0,sizeof(ans));
            bfs(i);
            for(int j=i+1;j<=n;j++){
                if(ans[j][1]==2){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
