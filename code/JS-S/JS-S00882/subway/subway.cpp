#include<bits/stdc++.h>
using namespace std;
#define INF 1e18+7
long long C,n,m,D,Q,k,W[1000007],d[1000007],x,y,w,s,t;
struct node{
    long long t,w;
};
bool operator<(const node&a,const node&b){
    return a.w>b.w;
}
priority_queue<node>q;
vector<node>a[1000007];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>Q;
    for(int i=0;i<m;i++)cin>>W[i];
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++)cin>>y>>w,y--,x=i+m,a[x].push_back({y,w}),a[y].push_back({x,w});
    }
    for(int i=0;i<Q;i++){
        cin>>s>>t;--s,--t;
        for(int j=0;j<m+n;j++)d[j]=INF;
        d[s]=0;
        q.push({s,0});
        while(q.size()>0){
            x=(q.top()).t;
            q.pop();
            for(int j=0;j<a[x].size();j++){
                y=a[x][j].t,w=a[x][j].w;
                if(d[y]>d[x]+w)d[y]=d[x]+w,q.push({y,d[y]});
            }
        }
        cout<<W[s]+W[t]+d[t]<<endl;
    }
    return 0;
}
