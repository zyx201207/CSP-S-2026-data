#include<bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll Maxn=2e5+10;

ll n,m;
ll a[Maxn];
vector<ll> line;
vector<bool> t(Maxn);

ll dfs(ll m){
	ll ans=-1;
	if(m==0){
		ans=line[0];
		for(ll i=1;i<line.size();i++){
			ans=ans&line[i];
		}
	}
	else{	
		for(ll i=0;i<n;i++){
			if(!t[i]){
				t[i]=1;
				line.push_back(a[i]);
				ans=max(ans,dfs(m-1));
				t[i]=0;
				line.pop_back();
			}
		}
	}
	return ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(m);
	return 0;
}

