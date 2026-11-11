#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005],len[500005];
vector<int> V[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		V[a[i]].push_back(i);len[a[i]]++;
	}
	for(int i=1;i<=n;i++){	
		int j=V[a[i]][len[a[i]]-1]+1;
		ans[a[i]]++;
		while(j<=n){
			ans[a[j]]++;
			j=V[a[j]][len[a[j]]-1]+1;
		}
	}
	for(int i=1;i<=m;i++){
		if(i!=m)cout<<ans[i]<<" ";
		else cout<<ans[i];
	}
	return 0;
}