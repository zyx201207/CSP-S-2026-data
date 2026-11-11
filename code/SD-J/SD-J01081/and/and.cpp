#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n+1];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	if(m==1){
		cout<<x[n];
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			x[i]=x[i]&x[i-1];
		}
		cout<<x[n];
	}
	else {
		for(int i=n;i>n+1-m;i--){
			x[i-1]=x[i]&x[i-1];
		}
		cout<<x[n+1-m];
	}
	return 0;
}
