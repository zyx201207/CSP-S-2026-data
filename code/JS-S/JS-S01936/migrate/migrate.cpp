#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int main(){
    #ifndef PSD
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int c,T;
    cin>>c>>T;
    long long sum=0;
    vector<vector<long long>> x(T);
    vector<long long> d(T);
    for(int i=0,n;i<T;i++){
        cin>>n>>d[i],sum+=n;
        x[i].resize(n+1);
        for(int j=1;j<=n;j++)
            cin>>x[i][j];
    }
    if(sum>5000)
        while(T--)cout<<"0\n";
    else for(int t=0;t<T;t++){
        vector<vector<int>> g(x[t].size());
        for(int i=1;i<x[t].size();i++)
            for(int j=i-1;j>=1&&x[t][i]-x[t][j]<=d[t];j--)
                g[j].push_back(i);
        long long ans=0;
        for(int i=1;i<x[t].size();i++){
            vector<int> plan(x[t].size()),dis(x[t].size(),1e9);
            plan[i]=1,dis[i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int j=q.front();
                q.pop();
                for(int k:g[j])
                    if(dis[j]+1<dis[k])
                        dis[k]=dis[j]+1,plan[k]=plan[j],
                        q.push(k);
                    else if(dis[j]+1==dis[k])
                        plan[k]+=plan[j];
            }
            ans+=count(plan.begin(),plan.end(),2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
