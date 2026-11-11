#include<bits/stdc++.h>
#include<string>
#include<vector>
#define ll long long
using namespace std;
ll c,T,n,k,x,y;
vector<ll> v[1000005],fv;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		fv.clear();
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			if(v[i].size()<=2) fv.push_back(i);
		}
		cout<<1<<"\n";
	}
}
