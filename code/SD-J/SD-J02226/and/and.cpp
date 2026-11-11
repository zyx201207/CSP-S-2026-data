#include<bits/stdc++.h>
using namespace std;
int n,m,b[1000005];
int a[1000005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			b[i]&=a[i+j];
		}
	}
	sort(b,b+n);
	cout<<b[n-1];
	return 0;
} 
