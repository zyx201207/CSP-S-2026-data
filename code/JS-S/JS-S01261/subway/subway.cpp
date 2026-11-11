#include<algorithm>
#include<string.h>
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
typedef pair<ll,int> pr2;
const int M=5e5+5;
const int N=505;
ll w[M];
vector<pr>station_sides[M];
vector<pr>line_sides[N];
vector<pr>sides[N];
ll min_size[N][N];
bool f[N];
bool cmp(pr x,pr y){
    return x.second<y.second;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int bc;
    scanf("%d",&bc);//the number of subtasks
    int n,m,d,q;
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int a;
            ll t;
            scanf("%d%lld",&a,&t);
            station_sides[a].push_back(make_pair(i,t));
            line_sides[i].push_back(make_pair(a,t));
        }
    }
    //build the line map
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        priority_queue<pr2,vector<pr2>,greater<pr2> >que;
        que.push(make_pair(0,i));
        while(!que.empty()){
            pr2 now=que.top();
            que.pop();
            if(f[now.second])continue;
            f[now.second]=true;
            min_size[i][now.second]=now.first;
            for(pr cg:line_sides[now.second]){
                for(pr nxt:station_sides[cg.first]){
                    if(!f[nxt.first])que.push(make_pair(now.first+cg.second+nxt.second,nxt.first));
                }
            }
        }
    }
    //find the answers
    for(int i=0;i<q;i++){
        int st,ed;
        scanf("%d%d",&st,&ed);
        ll ans=LLONG_MAX;
        for(pr c1:station_sides[st]){
            for(pr c2:station_sides[ed]){
                ll nowans=c1.second+c2.second+min_size[c1.first][c2.first];
                ans=min(ans,nowans);
            }
        }
        ans=ans+w[st]+w[ed];
        printf("%lld\n",ans);
    }
    return 0;
}