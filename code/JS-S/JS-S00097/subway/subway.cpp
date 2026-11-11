#include "bits/stdc++.h"
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int t[N],dis[N];

struct node{
    int e;
    int w;
};
vector<node> v[N];
priority_queue <int> qa;

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>t[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            v[i+m].push_back({a,b});
            v[a].push_back({i+m,b});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        memset(dis,0,sizeof(dis));
        int sum=t[x]+t[y];
        qa.push(x);
        while(qa.size()){
            int s=qa.top();
            qa.pop();
            if(s==y)break;
            for(int i=0;i<v[s].size();i++){
                int eu=v[s][i].e,wu=v[s][i].w;
                if(dis[eu]==1)continue;
                dis[eu]=1;
                qa.push(eu);
                sum+=wu;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
