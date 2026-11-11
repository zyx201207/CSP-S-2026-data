#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],m,f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		ll ma=0;
		for(int i=1;i<n;i++){
			for(int j=2;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==n){
		ll x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	else if(a[n]<=4){
		ll x=(long long)lower_bound(a+1,a+n+1,4);
		if(n-x+1>=m){
			cout<<4;
			return 0;
		}
		else{
			x=(long long)lower_bound(a+1,a+n+1,3);
			if(n-x+1>=m){
				cout<<3;
				return 0;
			}
			ll y=(long long)lower_bound(a+1,a+n+1,2);
			if(n-y+1+n-x+1>=m){
				cout<<2;
				return 0;
			}
			if(n-x+1+y-1>=m){
				cout<<1;
				return 0;
			}
			cout<<0;
			return 0;
		}
	}
	else{
		memset(f,sizeof(f),-1);
		f[1]=a[1];
		for(int j=m;j>=1;j--){
			f[j]=max(f[j-1]&a[i],f[j]);
		}
		cout<<f[m];
	}
	return 0;
}  
