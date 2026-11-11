#include <bits/stdc++.h>
using namespace std;
int main){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[31];
	cin>>n>>m;
	for (inr i=1;i<=n;i++){
		int b;
		cin>>b;
		while (b!=0){
			int c=0;
			a[c]+=b%2;
			b/=2;
			c++;
		}
	}
	int c[31]={1};
	for (int i=1;i<31;i++){
		c[i]=c[i-1]*2;
	}
	for (int i=30;i>=0;i--){
		if (a[i]>=m){
			cout<<c[i];
			break;
		}
	}
	return 0;
}
