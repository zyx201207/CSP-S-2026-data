#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,Min,mincnt=0,ctt;
long long a[N],ans[N];
vector<long long> G[N];
queue<long long> q;
void bfs(int a,int b){
    q.push(a);
    memset(ans,0x7f,sizeof(ans));
    ans[a]=0;
    while(!q.empty()){
        long long x=q.front();
        q.pop();
        if(x>b)continue;
        if(x==b){
            if(ans[x]<Min){
                Min=ans[x];
                mincnt=1;
            }
            else if(ans[x]==Min)mincnt++;
            ans[b]=0x7f7f7f7f7f7f7f7f;
            continue;
        }
        for(int i=0;i<G[x].size();i++){
            if(ans[G[x][i]]>ans[x]+1){
                ans[G[x][i]]=ans[x]+1;
                q.push(G[x][i]);
            }

        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]>d)break;
                G[a[j]].push_back(a[i]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                Min=1e18+1,mincnt=0;
                bfs(i,j);
                if(mincnt==2)ctt++;
            }
        }
        cout<<ctt;
    }
    return 0;
}
