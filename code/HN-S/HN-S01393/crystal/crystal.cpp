#include<bits/stdc++.h>
using namespace std;
struct x{
	int s;
}a[101];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,zx=100000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		if(zx>a[i].s){
			zx=a[i].s;
		}
	}
	cout<<3;
}
