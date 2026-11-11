#include <bits/stdc++.h>
using namespace std;
long long a[51245];
int main() {
	long long z;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		z+=a[i];
	}
	z/=n;
	int b;
	int q,h;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==z+j){
				h=j;
			}
			if(a[i]==z-j){
				q=j;
			}
		}
		
	}
	if(h>q){
		b=z-q;
	}else if(h<q){
		b=z+h;
	}
	//cout<<b<<" ";
	long long js=0;
	for(int i=1; i<=n; i++) {
		if(m==0) {
			break;
		} else {
			for(int j=1; j<=n; j++) {
				for(int s=0; s<=m; s++) {
					if(a[i]==a[j]+s) {	
						if(a[j]+s==b) {
							js++;
							m-=s;
							//cout<<a[j]+s<<" ";
						}
					}
				}
			}
		}

	}
	//cout<<z;
	cout<<js;
	return 0;
}
