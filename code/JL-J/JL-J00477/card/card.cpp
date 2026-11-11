#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync with stdio(false);
	cin.tie(nullptr);
fropen("card.in","r",stdin);
fropen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>first(m+1,-1);
	for(int i=1;i<=n;i++){
		if(first[a[i]]==-1){
			first[a[i]]=i;
			}
	}
	long long ans=0;
	for(int j=1;j<=m;j++
	ans+=first[x];
return 0;
}

