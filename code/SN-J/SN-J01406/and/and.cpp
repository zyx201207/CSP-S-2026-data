#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],m,k[10000005],o;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		k[o]=a[i];
		for(int j=2;i<=n;j++){
			k[o]=a[j] and k[o];
		}
		o++;
	}
	sort(k+1,k+o+1);
	cout<<k[o];
	return 0;
}
