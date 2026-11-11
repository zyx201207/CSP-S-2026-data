//SN-J00748  张哲瀚  西安市第八十九中学  
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=0;
		for(int i=1;i<=n;i++){
			c[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			b[i]+=c[i]%2;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
