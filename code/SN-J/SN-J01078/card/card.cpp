#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int a[N],ans[N];
vector<int> idx[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		idx[a[i]].push_back(i);
	}
	set<int> s;
	for(int i=1;i<=n;i++){
		if(s.find(i)!=s.end()) continue;
		bool jump=0;
		for(int j=i;j<=n;j++){
			if(jump) s.insert(j);
			ans[a[j]]+=jump+1;
//			cout << j << "\n";
			auto x=upper_bound(idx[a[j]].begin(),idx[a[j]].end(),j);
			if(x!=idx[a[j]].end()) ans[a[j]]--,j=*x-1;
//			cout << j << "\n";
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
