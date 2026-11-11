#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	long long maxn1=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
		maxn1&=a[i];
	}long long maxn2=a[n-m]; 
	for(int i=n-m+1;i<n;i++){
		maxn2&=a[i];
	}cout<<max(maxn1,maxn2);
	return 0;
}
