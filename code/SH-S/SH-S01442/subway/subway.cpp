#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f
#define ll unsigned long long
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y,a,l1,l2;
    ll t;
    cin>>c>>n>>m>>d>>q;
    vector<ll> w(m+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    vector<int> k(n+1);
    //vector<vector<int> > a(n+1);
    //vector<vector<int> > t(n+1);
    vector<vector<int> > p(m+1);
    vector<vector<ll> > pt(m+1);
    vector<vector<ll> > sp(n+1);
    for(int i=1;i<=n;i++){
        sp[i].resize(n+1);
        for(int j=1;j<=n;j++) sp[i][j]=INF;
        sp[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        //a[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++) {
            cin>>a>>t;
            p[a].push_back(i);
            pt[a].push_back(t);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<p[i].size();j++){
            for(int k=j+1;k<p[i].size();k++){
                l1=p[i][j],l2=p[i][k];
                sp[l1][l2]=min(sp[l1][l2],pt[i][j]+pt[i][k]);
                sp[l2][l1]=sp[l1][l2];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                sp[i][j]=min(sp[i][j],sp[i][k]+sp[j][k]);
                sp[j][i]=sp[i][j];
            }
        }
    }
    ll ans,mid;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=INF;
        for(int j=0;j<p[x].size();j++){
            for(int k=0;k<p[y].size();k++){
                l1=p[x][j],l2=p[y][k];
                mid=sp[l1][l2]+pt[x][j]+pt[y][k];
                ans= (ans<=mid)?ans:mid;
            }
        }
        printf("%lld\n",w[x]+w[y]+ans);
    }
    return 0;
}
