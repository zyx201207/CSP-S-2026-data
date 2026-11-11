#include<bits/stdc++.h>
using namespace std;
const int N=503,M=1e6+7,D=25;
const long long inf=4e18;
int c,n,m,k,d,q,w[M],t,a,x,y;
vector<pair<int,int> > sta[M];
int tot;
long long e[N][N],res;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    tot=n+m;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            tot++;
            sta[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            e[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        for(pair<int,int> j:sta[i]){
            int s1=j.first,c1=j.second;
            for(pair<int,int> k:sta[i]){
                int s2=k.first,c2=k.second;
                if(s1==s2)continue;
                e[s1][s2]=min(e[s1][s2],1ll*c1+c2);
                e[s2][s1]=min(e[s2][s1],1ll*c1+c2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
        }
    }
    while(q--){
        cin>>x>>y;
        res=inf;
        for(pair<int,int> i:sta[x]){
            int s1=i.first,c1=i.second;
            for(pair<int,int> j:sta[y]){
                int s2=j.first,c2=j.second;
                res=min(res,e[s1][s2]+c1+c2+w[x]+w[y]);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}