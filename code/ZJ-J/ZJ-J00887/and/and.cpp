#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mp[200005],a[200005],nw[200005],ans;
vector<int>vec[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		mp[i]=1;
		cin>>a[i];
		int k=a[i],w=1;
		while(k){
			if(k%2)vec[w].push_back(i);
			k/=2;
			w++;
		}
	}for(int i=31; i>=1; i--){
		memset(nw,0,sizeof nw);
		if(vec[i].size()<m)continue;
		ll t=0;
		for(int u:vec[i]){
			if(mp[u])t++;
		}if(t>=m){
			ans+=(1<<(i-1));
			for(int u:vec[i]){
				if(mp[u])nw[u]=1;
			}
		}for(int i=1; i<=n; i++)mp[i]=nw[i];
	}cout<<ans;
	return 0;
}