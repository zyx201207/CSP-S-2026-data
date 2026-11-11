#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	int maxx=0;
	int a[300005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>	a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}