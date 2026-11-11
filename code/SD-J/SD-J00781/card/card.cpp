#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin >> n >> m;
	vector<vector<int>> a(n+1,vector<int>(2));
	unordered_map<int,int> num;
	for (int ver=1;ver<=n;ver++){
		int i; cin >> i;
		a[ver][0]=i;
		a[ver][1]=1;
		if (num.find(i)!=num.end()){
			a[num[i]-1][1]-=1;
			a[ver][1]+=1;
			num[i]=ver;
		}
		else num.insert({i, ver});
	}
	vector<int> ans(m,0);
	for (int i=1;i<=n;i++){
		a[i][1]+=a[i-1][1];
		ans[a[i][0]]+=a[i][1];
	}
	for (int i=1;i<=m;i++){
		cout << ans[i];
		cout << ((i==m)?'\n':' ');
	}
	return 0;
}
