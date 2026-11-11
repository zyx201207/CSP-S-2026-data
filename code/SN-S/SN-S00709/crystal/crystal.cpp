#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,qer,wqe;
ll m;
ll a[N],b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qer=abs(a[i]);
		wqe=a[i]-a[i-1];
	}
	if(qer>100){
		int cnt=0,ds;
		for(int i=1;i<=n;i++){
			cnt+=1;
			if(ds>m){
				cout<<i-1;
				return 0;
			}
			ds=cnt*wqe;
		}
	}
	sort(a+1,a+1+n);
	ll mas=a[n];
	for(int i=1;i<=n;i++) {
		a[i]=mas-a[i];
//		cout<<a[i]<<" ";
	}

	for(int i=n;i>=1;i--) {
		b[i]=b[i+1]+a[i];
//		cout<<b[i]<<" ";
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i+1;j++){
			ll cnt=0;
			cnt=b[j]-b[j+i]-i*a[j+i-1];
			if(cnt<=m) {
				cout<<i;
				return 0;
			}
			
			
		}
	}
	cout<<1;
	
	
	
	return 0;
} 
