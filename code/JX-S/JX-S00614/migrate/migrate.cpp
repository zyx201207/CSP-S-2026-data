#include <bits/stdc++.h>
using namespace std;
constexpr int N=2000005;
long long n,d,ans=0;
long long pos[N],dis[N];
vector<pair<int,bool>> xgs;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>pos[i];
            dis[i]=pos[i]-pos[i-1];
        }
        bool lam=0;
        xgs.clear();
        ans=0;
        for (int i=2;i<=n;i++){
            if (dis[i-1]+dis[i]<=d){
                if (lam && dis[i-2]+dis[i-1]+dis[i]>d)xgs.push_back({i,1});
                lam=true;
            }else lam=0;
            if (dis[i]>d){
                xgs.push_back({i,0});
            }
        }
        for (int i=0;i<xgs.size();i++){
            if (xgs[i].second==0)continue;
            long long lr,rr;
            if (i==0)lr=1;
            else{
                if (xgs[i-1].second){
                    lr=xgs[i-1].first-2;
                }else{
                    lr=xgs[i-1].first;
                }
            }
            if (i+1==xgs.size()){
                rr=n;
            }else{
                if (xgs[i+1].second){
                    rr=xgs[i+1].first-1;
                }else{
                    rr=xgs[i+1].first-1;
                }
            }
            ans+=(xgs[i].first-2-lr)*(rr-xgs[i].first+1);
        }
        cout<<ans<<'\n';
    }
	return 0;
}
