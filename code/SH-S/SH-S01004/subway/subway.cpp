#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int maxn=500005;
int c,n,m,d,q;
int w[maxn];
int s[505];
vector<PII>subway[505];
bool vis[maxn];
//w:从每个地铁站的地铁口走到站厅需要的时间
//c:测试点编号
//n:地铁线路数
//m:地铁站数
//d:每个地铁站最多被几条线路经过
//q:出行计划数
int bfs(int st,int ed){
    int cnt=0;
    queue<int>q1;
    queue<int>q2;
    q1.push(st);
    vis[st]=true;
    bool flag=true;
    while(flag){
        while(!q1.empty()&&flag){
            int pos=q1.front();
            q1.pop();
            for(int i=0;i<s[pos];i++){
                if(subway[pos][i].first==ed){
                    flag=false;
                    cnt++;
                    break;
                }
                if(!vis[subway[pos][i].first]){
                    q2.push(subway[pos][i].first);
                    vis[subway[pos][i].first]=true;
                }
            }
        }
        if(flag){
            cnt++;
        }
        while(!q2.empty()&&flag){
            int pos=q2.front();
            q2.pop();
            for(int i=0;i<s[pos];i++){
                if(subway[pos][i].first==ed){
                    flag=false;
                    cnt++;
                    break;
                }
                if(!vis[subway[pos][i].first]){
                    q1.push(subway[pos][i].first);
                    vis[subway[pos][i].first]=true;
                }
            }
        }
        if(flag){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        s[i]=k;
        for(int j=1;j<=k;j++){
            int a1,t1;
            scanf("%d%d",&a1,&t1);
            subway[i].push_back({a1,t1});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=bfs(x,y)*(subway[1][0].second);
        printf("%d\n",ans);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
