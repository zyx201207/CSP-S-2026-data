#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])b[a[i]]=i;
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}

