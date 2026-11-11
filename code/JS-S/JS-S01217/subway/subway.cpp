#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 500005;
vector<vector<int>> node(MAXN);//stages every line connects
vector<vector<int>> line(MAXM);//lines every stage connects
int times[MAXM][MAXN];//time[node][line],node->line times
bool vis[MAXM];

long long ans = 0;
long long minans = LONG_MAX;
void dfs(int start,int end,int curline){
    if(start==end){
        minans = min(ans,minans);
        return;
    }
    int SZ=line[start].size();
    vis[start] = true;
    for(int i=0;i<SZ;i++){
        long long temp1 = ans;
        int l = line[start][i];
        if(l==curline) continue;
        ans+=times[start][l];
        long long temp2 = ans;
        for(int j=0;j<node[l].size();j++){
            ans = temp2;
            int cur = node[l][j];
            if(vis[cur]==true) continue;
            ans+=times[cur][l];
            dfs(cur,end,i);
            vis[cur]=false;
        }
        ans = temp1;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(vis,false,sizeof(vis));
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int w[m+2];
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    int k,a,t;
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> a;
            node[i].push_back(a);
            line[a].push_back(i);
            cin >> t;
            times[a][i]=t;
        }
    }
    int start,end;
    for(int i=0;i<q;i++){
        cin >> start >> end;
        dfs(start,end,-1);
        minans+=w[end];
        minans+=w[start];
        cout << minans << endl;
    }
    return 0;
}
