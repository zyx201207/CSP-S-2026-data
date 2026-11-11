#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,mx=0,a[N],b[5];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool A=1,B=1,C=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2!=1) A=0;
		if(a[i]!=i-1) B=0;
		if(a[i]>4){
			C=0;
		}else{
			b[a[i]]++;
		}
		mx=max(mx,a[i]);
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans, a[i] & a[j] );
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int t=a[1],ans=0;
		for(int i=2;i<=n;i++){
			t&=a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,t&~a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(A){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(B){
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(C){
		if(b[4]>=m) cout<<4;
		else if(b[3]>=m) cout<<3;
		else if(b[3]+b[2]>=m) cout<<2;
		else if(b[3]+b[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(n<=20){
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	int t=1;
	while(mx){
		mx/=2;
		t*=2;
	}
	cout<<t;
	return 0;
}