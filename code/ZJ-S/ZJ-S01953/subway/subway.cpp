#include<bits/stdc++.h>
#include<bits/extc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace __gnu_cxx;
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,D,q,tme[500010],len[1010],d[510][510];
vector<pair<int,int> > a[510],dd[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    IOS
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++){
        cin>>tme[i];
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++){
        d[i][i]=0;
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            int x,time;cin>>x>>time;
            a[i].push_back({x,time});
            dd[x].push_back({i,time});
        }
    }
    for(int i=1;i<=n;i++){
        for(auto[x,time]:a[i]){
            for(auto[j,time2]:dd[x]){
                if(i==j) continue;
                int ii=min(i,j),jj=max(i,j);
                d[ii][jj]=min(d[ii][jj],time+time2);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                d[i][j]=min(d[i][j],d[min(i,k)][max(i,k)]+d[min(j,k)][max(j,k)]);
            }
        }
    }
    while(q--){
        int l,r,ans=inf;
        cin>>l>>r;
        for(auto[i,time1]:dd[l]){
            for(auto[j,time2]:dd[r]){
                ans=min(ans,time1+time2+d[min(i,j)][max(i,j)]);
            }
        }
        cout<<tme[l]+tme[r]+ans<<"\n";
    }
    return 0;
}
