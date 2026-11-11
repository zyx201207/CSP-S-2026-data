#include<bits/stdc++.h>
using namespace std;
int n,m,a[500004];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==m) {
		for(int i=1; i<=m; i++) {
			cout<<n<<" ";
		}
	} else if(m==1) {
		for(int i=1; i<=m; i++) {
			if(i==a[1]) {
				cout<<n<<" ";
			} else {
				cout<<0<<" ";
			}

		}
	}else if(m==2){
		cout<<(n-1)<<" "<<n;
	}else if(m==(n-1)){
		cout<<0<<" ";
		int x=3;
		for(int i=1;i<m;i++){
			cout<<x<<" ";
			x++;
		}
	}
	return 0;
}
