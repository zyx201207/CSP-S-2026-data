#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > subs[510];
int wait[500010];
vector<pair<int> > graph[500010][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,q;
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++){
        cin>>wait[i];
    }for(int i=1;i<=n;i++){
        int k;cin>>k;
        subs.assign(k,{0,0});
        for(int j=0;j<k;j++){
            cin>>subs[i][j].first>>subs[i][j].second;
        }
    }while(q--){
    	int u,v;
    	cin>>u>>v;
    	cout<<abs(v-u)<<endl;
    }
    return 0;
}
