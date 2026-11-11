#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[201010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int x=a[i]&a[j]; 
				maxx=max(maxx,x);
			}
		}cout<<maxx;
		return 0;
	}else if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}cout<<x;
		return 0;
	}int x=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
	}cout<<x;
	return 0;
}
