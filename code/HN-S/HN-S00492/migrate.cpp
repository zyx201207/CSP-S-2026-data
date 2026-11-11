#include<bits/stdc++.h>
using namespace std;
int c,n;
long long d;
long long x[5005];
int dis[5005],ways[5005];
int ans;
void BFS(int st){
    queue<int> q;
    memset(dis,0,sizeof(dis));
    memset(ways,0,sizeof(ways));
    q.push(st);
    dis[st]=1;
    ways[st]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int l=now;x[now]-x[l]<=d&&l>=1;l--){
            if(!dis[l]){
                q.push(l);
                dis[l]=dis[now]+1;
            }
            if(dis[l]==dis[now]+1){
                ways[l]+=ways[now];
                if(ways[l]>2) ways[l]=3;
            }
        }
        for(int r=now;x[r]-x[now]<=d&&r<=n;r++){
            if(!dis[r]){
                q.push(r);
                dis[r]=dis[now]+1;
            }
            if(dis[r]==dis[now]+1){
                ways[r]+=ways[now];
                if(ways[r]>2) ways[r]=3;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ways[i]==2) ans++;
    }
}
void Work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        BFS(i);
    }
    cout<<ans/2<<'\n';
    ans=0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>c>>t;
    while(t--){
        Work();
    }
    return 0;
}
/*
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/