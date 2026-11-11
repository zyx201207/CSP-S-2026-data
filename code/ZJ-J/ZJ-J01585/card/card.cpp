#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int n,m;
int a[N];
int ans[M];
vector<int> g[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int p=g[a[j]].size()-1;
			if(g[a[j]][p]>j) j=g[a[j]][p];
			ans[a[j]]++;
//			cout << i << " " << a[j] << endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

