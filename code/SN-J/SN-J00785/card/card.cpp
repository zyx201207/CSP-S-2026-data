#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];c[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<' ';
	return 0;
}

