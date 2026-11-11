#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3010;
int c,t;
int n;ll d;
ll a[N];
int dist[N];
struct node{
    int x;
    int dis;
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //cout<<i<<" "<<j<<'\n';
                queue<node> q;
                q.push({i,0});
                for(int k=i;k<=j;k++)
                    dist[k]=-1;
                int cnt=0,distant=0;
                while(!q.empty()){
                    node tmp=q.front();q.pop();
                    int x=tmp.x,dis=tmp.dis;
                    //cout<<"x : "<<x<<" dis : "<<dis<<'\n';
                    if(dis>distant&&distant!=0) break;
                    if(x==j){
                        if(cnt==0){
                            cnt++;
                            distant=dis;
                        }
                        else if(distant==dis) cnt++;
                    }
                    if(dist[x]<dis&&dist[x]!=-1) continue;
                    dist[x]=dis;
                    for(int k=x+1;k<=j;k++){
                        if(a[k]-a[x]>d) break;
                        q.push({k,dis+1});
                    }
                }
                //cout<<"cnt = "<<cnt<<" d = "<<distant<<'\n';
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 1
4 3
1 2 4 5
*/
