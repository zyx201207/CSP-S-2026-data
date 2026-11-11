#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
