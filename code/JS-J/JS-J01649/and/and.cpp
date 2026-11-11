#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=LLONG_MIN;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>mx){
				mx=a[i];
			}
		}
		cout<<mx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&((a[i]&a[j])>mx)){
					mx=(a[i]&a[j]);
				}
			}
		}
		cout<<mx;
	}else if(m==n-1){
		sort(a+1,a+n+1,greater<int>());
		int x=a[1];
		for(int i=1;i<n;i++){
			x=(a[i]&x);
		}
		cout<<x;
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		int x=a[1];
		for(int i=2;i<=m;i++){
			x=(x&a[i]);
		}
		cout<<x;
	}
	return 0;
}
