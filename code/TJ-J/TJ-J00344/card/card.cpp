#include <bits/stdc++.h>
using namespace std;
int a[500007],s[300007];
int vis[500007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		s[a[i]]++;
	}
	for (int i=1;i<=m;i++){
		cout <<s[i] <<" ";
	}
	return 0;
}
