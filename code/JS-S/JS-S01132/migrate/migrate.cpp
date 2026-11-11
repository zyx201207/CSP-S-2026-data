#include<algorithm>
#include<iostream>
#include<iterator>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

struct node{
    int m_u;
    int m_w;

    node(int _U=0,int _W=0){
        m_u=_U;
        m_w=_W;
    }
};

ll ans;
ll n,d,t;
ll c,Q,p;
ll x[2000005];
int dis[2000005];
int vis[2000005];
vector<node> arr[2000005];
priority_queue<PII,vector<PII>,less<PII> > q;

void add(int _u,int _v,int _w){
    arr[_u].push_back(node(_v,_w));
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&Q);
    while(Q--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",x+i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[i]-x[j]<=d){
                    add(i,j,1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            memset(dis,0,sizeof(dis));
            dis[i]=1;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[j-1]<=d){
                    dis[j]=dis[j-1]+1;
                }
            }
            t=0;
            for(int j=i+1;j<=n;j++){
                if(dis[j]&1){
                    continue;
                }
                if(dis[j]==2){
                    t=j;
                }
                if(dis[j]>2){
                    if(x[j]-x[t]<=d&&x[j]-x[i]>d){
                        ans++;
                    }
                    t=j;
                }
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
