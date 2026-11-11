#include <bits/stdc++.h>
using namespace std;
int n,m,c1,c2,c3;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c1++;
		c2++;
		c3++; 
	}
	cout<<c1<<c2<<c3;
	return 0;
}
