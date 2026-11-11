#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[600000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=0;
	for(int i=1;i<=n/2;i++){
		h+=a[i];
	}
	cout<<h<<a[n/2+1]<<a[n]+a[n-1];
	return 0;
}