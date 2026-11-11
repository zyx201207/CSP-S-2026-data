#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],last[300010],res[300010];
int main() {
	//freopen("E:/down/card/card6.in","r",stdin);
	//freopen("E:/down/card/card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i;j<=n;j++){
			res[a[j]]++;
			j=last[a[j]];
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<res[i]<<" ";
	}
	return 0;
}