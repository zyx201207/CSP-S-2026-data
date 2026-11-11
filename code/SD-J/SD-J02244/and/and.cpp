#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000+10],b[100000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n;i++)
		b[i]=a[n-1-i];
	cout<<b[n/2];
	return 0;
}
