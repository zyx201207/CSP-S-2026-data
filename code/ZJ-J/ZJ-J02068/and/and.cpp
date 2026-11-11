#include<bits/stdc++.h>
#define inf 20005
using namespace std;
int n,m,a[inf],f[inf];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//  no"//"!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		f[i]=a[i];
		for(int j=1;j<i;j++){
			f[i]=max(f[i],f[j]&a[i]);
		}
	}
	cout<<f[n];
	return 0;
}
