#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,i,d,j,q,w[100005],k[505];
vector<ll> vec1[500005];
vector<pair<ll,ll> > vec[505];
struct lc{
    ll z,tim,ce;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
  // freopen("subway4.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++){
        cin>>w[i];
    }
    for(i=1;i<=n;i++){
        cin>>k[i];
        for(j=1;j<=k[i];j++){
            ll x,t;
            cin>>x>>t;
            vec[i].push_back({x,t});
            vec1[x].push_back(i);
        }
    }

    while(q--){
        ll x,y;
        map<ll,ll> mp;
        cin>>x>>y;
        queue<lc> que;
        lc no;
        no.z=x;
        no.tim=w[x];
        no.ce=0;
        que.push(no);
        ll ans=1000000000;
        while(que.size()!=0){
            lc top=que.front();
           // cout<<top.z<<' '<<top.tim<<' '<<top.ce<<'\n';
            que.pop();
            if(mp[top.z]!=0&&mp[top.z]<top.tim){
                continue;
            }
            mp[top.z]=top.tim;
            if(top.z==y){
                ans=min(ans,w[top.z]+top.tim);
                continue;
            }
            for(auto it:vec1[top.z]){
                    ll jis=0;
                for(auto itt:vec[it]){
                    if(itt.first==top.z){
                        jis=itt.second;
                        break;
                    }
                }
                for(auto itt:vec[it]){
                    if(itt.first==top.z){
                        continue;
                    }
                    lc no;
                    no.ce=top.ce+1;
                    no.z=itt.first;
                    no.tim=itt.second+top.tim+jis;
                    que.push(no);
                }
            }
        }
     //   /if(ans==10000000000){
           // ans=mp[y];
          //  cout<<1<<'\n';
          //  cout<<mp[y]<<'\n'<<'\n';
      //  }
        cout<<ans<<'\n';
    }
    return 0;
}
