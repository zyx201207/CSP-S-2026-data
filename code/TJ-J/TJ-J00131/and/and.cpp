#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans,s,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max(a[i],k);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=2;i++){
		s+=(a[i]&a[i+1]);
	}
	for(int i=2;i<=n;i++){
		s+=(s&a[i+1]);
	}
	cout<<s;
	return 0;
}
