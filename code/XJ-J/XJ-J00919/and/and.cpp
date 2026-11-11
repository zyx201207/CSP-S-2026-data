#include<bits/stdc++.h>
using namespace std;
int n,m,c,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n*n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			b[c]=0;
			b[c]=a[i]^a[j];
			c++;
		}
	}
	for(int i=0;i<c;i++) {
		b[i+1]=max(b[i],b[i+1]);
	}
	cout<<b[c+1]+12;
	return 0;
}