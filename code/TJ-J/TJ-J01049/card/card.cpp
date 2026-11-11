#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,tmp;cin>>n>>m;
	vector<ll>ans(m+1,0);
	vector<ll>v(n+1);
	for(ll i=1;i<=n;i++){
		cin>>tmp;
		v[i]=tmp;
	}
	vector<ll> g;
	vector<ll> nw(m+1,0);
	for(ll i=1;i<=n;i++){
		ll l_1=0;
		for(ll j=i;j<=n;j++){
			nw[v[j]]++;
			if(nw[v[j]]==1) g.push_back(v[j]);
			else{
				for(ll k=0;k<g.size();k++){
					if(g[k]==v[j]){l_1=max(l_1,k+1);break;}
				}
				g.push_back(v[j]);
				nw[v[j]]=1;
			}
		}
		for(ll j=l_1;j<g.size();j++){
			//cout<<g[j]<<' '; 
			ans[g[j]]++;
		}
		//cout<<'\n';
		for(ll &i:nw) i=0;
		g.clear();
	}
	for(ll i=1;i<=ans.size()-1;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//C:\Users\Administrator\Desktop\TJ-J01049\card\collect2.exe	[Error] ld returned 1 exit status
