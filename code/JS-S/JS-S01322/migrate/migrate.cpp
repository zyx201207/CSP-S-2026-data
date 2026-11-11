#include<bits/stdc++.h>
using namespace std;
int c,t,n,minn;
long long d,dist[2000005];
bool bfs(int u,int v){
    int sum=0;
    minn=1e9;
    queue<pair<int,int>>q;
    q.push({u,0});
    while(q.size()){
        int ri=q.front().first;
        int rd=q.front().second;
        q.pop();
        if(rd>minn)continue;
        if(ri==v){
            if(sum==0)sum++,minn=rd;
            else if(rd==minn)sum++;
            if(sum>2)return 0;
            continue;
        }
        for(int i=ri+1;i<=v;i++){
            if(dist[i]-dist[ri]<=d)q.push({i,rd+1});
        }
    }
    if(sum==2)return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>dist[i];
        for(int i=1;i<=n;i++){
            bool flag=1;
            for(int j=i+3;j<=n;j++){
                if(flag==1&&bfs(i,j))ans++;
                else flag=0;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
