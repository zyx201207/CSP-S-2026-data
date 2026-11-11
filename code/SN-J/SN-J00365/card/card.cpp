#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[s]++;
	}
	a[0]=0;
	for(int i=1;i<=m;i++){
		a[i]=a[i]+a[i-1];
		cout<<a[i]<<' ';
	} 

	return 0;
}
