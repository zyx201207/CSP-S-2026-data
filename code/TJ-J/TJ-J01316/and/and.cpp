#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j]>maxn) maxn=a[i]&a[j];
		}
	}
	cout<<maxn;
	return 0;
}
