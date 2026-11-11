#include<bits/stdc++.h>
using namespace std;
long long a[1000000000000009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		max(a[i],a[i+1]);
		l=a[i] and a[i+1];
	}cout<<l;
	return 0;
}
