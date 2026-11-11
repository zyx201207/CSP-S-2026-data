#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],d[300010],s[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]=i;
	}
	for (int o=1;o<=n;o++)
		for (int i=o;i<=n;i=d[a[i]]+1)
			++s[a[i]];
	for (int i=1;i<m;i++) cout<<s[i]<<' ';
	cout<<s[m]<<'\n';
	return 0;
}
