#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>v(n+1);
	vector<ll>ans(m+1);
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		map<ll,ll>mp;
		vector<ll>vv;
		for(int j=i;j<=n;j++){
			if(mp[v[j]]==0){
				mp[v[j]]++;
				vv.push_back(v[j]);
			}
			else {
				int f=0;
				for(ll a=0;a<vv.size();a++){
					if(vv[a]==v[j]){
						f=a;
						break;
					}
				}
				while(vv.size()>f){
					mp[vv.back()]--;
					vv.pop_back();
				}
				mp[v[j]]=1;
			}
		}
		for(int x=1;x<=m;x++){
			if(mp[x]>0)ans[x]++;
		}
		
	
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
