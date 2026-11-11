#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
vector<int> f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int o=f[a[j]][f[a[j]].size()-1];
			if(o!=j){
				j=o;
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
