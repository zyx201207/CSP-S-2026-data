#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m;
int a[N],ans[N];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int ti=1;ti<=n;ti++){
        vector<int>ca(n+1,0);
        vector<pair<bool,int> >v(m+1,make_pair(0,-1));
        for(int i=ti;i<=n;i++){
            if(v[a[i]].first){
                for(int j=v[a[i]].first;j<=ca.size();j++){
                    v[a[i]].first=0,v[a[i]].second=-1;
                    ca.pop_back();
                }
            }
            ca.push_back(a[i]);
            v[a[i]].second=ca.size();
            v[a[i]].first=1;
        }
        for(auto p:ca){
            ans[p]++;
        }
	}
	for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
	}
	return 0;
}
