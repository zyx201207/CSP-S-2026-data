#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int z=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(z<(a[i]&a[j])){
				z=a[i]&a[j];
			}
		}
	}
	cout<<z;
	return 0;
}
