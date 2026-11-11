#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define unsigned long long
#define PII pair<int,int>
const int N=5e5+10;
int w[N];
set<int> a[510];
vector<map<int,int> > t(510);
int c,n,m,d,nub;
struct node{
    int c,x,sum;//zhantai,subway's line,time;
};
queue<node> q;
void bfs(int c,int l,int sum,int en){
    q.push({c,l,sum});
    vector<vector<int> > vis(510,vector<int>(m));
    while(!q.empty()){
        node num=q.front();
        q.pop();
        if(num.c==en){
            cout<<num.sum<<'\n';
            return;
        }
        for(auto i:a[num.x]){
            if(vis[num.x][i]>num.sum || !vis[num.x][i]){
                vis[num.x][i]=num.sum;
                q.push({i,num.x,num.sum});
            }
        }
        for(int i=1;i<=n;i++){
            int times=num.sum+t[num.x][num.c]+t[i][num.c];
            if(a[i].count(num.c)&&(vis[i][num.c]>times||!vis[i][num.c])){
                vis[i][num.c]=times;
                q.push({num.c,i,times});
            }
        }
    }
}
int main(){
    IOS;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>nub;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].insert(x);
            t[i][x]=y;
        }
    }
    while(nub--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].count(l)){
                bfs(i,l,w[i]+t[i][l],r);
            }
        }
    }
    return 0;
}
