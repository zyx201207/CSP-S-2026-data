#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

        __gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>>run;
        vector<__gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>>::point_iterator>it;
vector<int>w(1);
vector<vector<int>>ans;
vector<vector<pair<int,int>>>tt;
const int maxn=5e6+5;
vector<vector<int>>onroad;
vector<pair<int,int>>qu;
using namespace std;
int c,n,m,d,q,a,b,k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>c>>n>>m>>d>>q;
    it.resize(m+1);
    tt.resize(n+1);
    onroad.resize(n+1,vector<int>(m+1,0));
    ans.resize(m+1,vector<int>(m+1,114514191));
    for(int i=0;i<m;i++){
        cin >>a;
        w.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >>k;
        for(int j=0;j<k;j++){
            cin >>a>>b;
            onroad[i][a]=b;
            tt[i].push_back({b,a});
        }
    }
    for(int i=0;i<q;i++){
        cin >>a>>b;
        qu.push_back({a,b});
    }
    for(int s=1;s<=m;s++){
        bitset<maxn>iq;
        iq.reset();
        iq[s]=1;
        it[s]=run.push({0,s});
        ans[s][s]=0;
        while(!run.empty()){
            pair<int,int>p=run.top();
            run.pop();
            iq[p.second]=0;
            for(int i=0;i<n;i++){
                if(onroad[i][p.second]){
                    for(auto pp:tt[i]){
                        if(pp.second!=p.second){
                            if(ans[s][pp.second]>p.first+onroad[i][p.second]+pp.first){
                                ans[s][pp.second]=p.first+onroad[i][p.second]+pp.first;
                                if(iq[pp.second]){
                                    run.modify(it[pp.second],{ans[s][pp.second],pp.second});
                                }
                                else {
                                    it[pp.second]=run.push({ans[s][pp.second],pp.second});
                                    iq[pp.second]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        //cout <<s<<"dj\n";
    }
    for(auto &p:qu){
        cout <<w[p.first]+w[p.second]+ans[p.first][p.second]<<"\n";
    }
    return 0;
}
