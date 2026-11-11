#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),ans(m+1,n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		unordered_map<int,int> mp;
		for(int j=i;j<=n;j++){
			mp[a[j]]++;
			if(mp[a[j]]==2){
				for(int k=v.size()-1;k>=0;k--){
					if(a[j]!=v[k])mp[v[k]]=0,v.pop_back();
					else break;
				}
				mp[a[j]]=1;
			}
			else v.push_back(a[j]);
		}
		for(int num:v){
			ans[num]++;
		}
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
