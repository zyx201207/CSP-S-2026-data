#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
vector <int> e[M];
int a[N],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[i]=x;
		e[x].push_back(i);
	}
	for(int i=1;i<=m;i++) sort(e[i].begin(),e[i].end());
	for(int i=1;i<=n;i++){
		int r=i;
		while(r<=n){
			ans[a[r]]++;
			int sizes=e[a[r]].size()-1,lst=e[a[r]][sizes];
			r=lst+1;
		} 
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
