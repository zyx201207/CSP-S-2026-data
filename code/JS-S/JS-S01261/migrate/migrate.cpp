#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
const int N=5005;
ll a[N];
int dis[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int bc;
    scanf("%d",&bc);//the number of subtasks
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dis,0,sizeof(dis));
        int n;
        ll d;
        scanf("%d%lld",&n,&d);
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        for(int i=0;i<n-1;i++){
            int nowmax=i,tcp=0;
            queue<pair<ll,ll> >que;que.push({i,0ll});
            while(!que.empty()){
                queue<pair<ll,ll> >nxt;
                int cc=nowmax;
                while(!que.empty()){
                    pair<ll,ll>now=que.front();
                    que.pop();
                    for(int j=cc+1;j<n&&abs(a[j]-a[now.first])<=d;j++){
                        dis[i][j]++;
                        nxt.push(make_pair(j,now.second+1));
                        nowmax=max(nowmax,j);
                    }
                }
                que=nxt;
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                //cout<<dis[i][j]<<" ";
                if(dis[i][j]==2)ans++;
            }
            //cout<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}