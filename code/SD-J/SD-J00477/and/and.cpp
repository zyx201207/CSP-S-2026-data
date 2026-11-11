#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000000000000],ans=99999999999999999999999,b[1000000000000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			b[i]=max(a[j],b[j]);
		}
	}
	for(int i=i;i<=m;i++){
		ans=min(ans,b[i]);
	}
	cout << ans; 
	return 0;
} 
