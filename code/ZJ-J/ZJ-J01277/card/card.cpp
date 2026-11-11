#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		cout<<m<<' ';
	} 
	return 0;
}
