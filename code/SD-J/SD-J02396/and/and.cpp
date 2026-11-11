#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,d;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[n];
		if(a[n]==0){
			cout<<'0';
			return 0;
		}
		d=max(d,a[n]);
	}
	if(m==1){
		cout<<d;
		return 0;
	}
	return 0;
}
