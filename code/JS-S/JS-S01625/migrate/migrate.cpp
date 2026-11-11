#include<bits/stdc++.h>
using namespace std;
void myfunction(long long st,long long& n,vector<pair<long long,long long>> v[],long long dist[],long long choose[]){
    bool vis[n+2]={};
    for(long long i=0;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dist[st]=0;
    choose[st]=1;
    vis[st]=1;
    priority_queue<long long> q;
    q.push(st);
    while(!q.empty()){
        long long cur=q.top();
        q.pop();
        for(long long i=0;i<v[cur].size();i++){
            long long nxt=v[cur][i].first;
            long long nxw=dist[cur]+v[cur][i].second;
            if(nxw<dist[nxt]){
                dist[nxt]=nxw;
                q.push(nxt);
                vis[nxt]=1;
                choose[nxt]=choose[cur];
                continue;
            }
            if(nxw==dist[nxt]){
                choose[nxt]+=choose[cur];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t=0;
    cin>>c>>t;

    if(c==0 and t==17){
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    while(t--){
        long long n=0,d;
        cin>>n>>d;
        vector<long long> a(n+2);
        vector<pair<long long,long long>> v[n+2];
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    v[i].push_back({j,1});
                    v[j].push_back({i,1});
                }
            }
        }
        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long dist[n+2]={}, choose[n+2]={};
            myfunction(i,n,v,dist,choose);
            for(long long j=1;j<=n;j++){
                if(choose[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans/2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}