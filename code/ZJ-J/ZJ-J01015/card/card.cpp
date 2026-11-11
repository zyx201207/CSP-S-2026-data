#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];
vector<int> v;
map<int,int> mp;
void push(int k)
{
	for(int x=0;x<v.size();x++) if(v[x]==k){
		int temp=v.size()-x-1;
		while(temp--) v.pop_back();
		return;
	}
	v.push_back(k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) push(a[j]);
		for(auto x:v) mp[x]++;
		v.clear();
	}
	for(auto x:mp) cout<<x.second<<" ";
	return 0;
}
