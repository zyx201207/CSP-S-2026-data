#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
const int M=1e12;
typedef long long ll;
ll n,m,a[N],mi=0x3f3f3f3f3f3f3f3f,b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int f1=1,f2=1;
	ll c,d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i==2){
			c=a[i]-a[i-1];
		}else if (i>2&&f1==1&&a[i]-a[i-1]!=c){
			f1=0;
		}
		if (f2==1&&a[i]!=a[1]){
			f2=0;
		}
	}
	if (f2){
		cout<<n;
	}else if (f1){
		int s;
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++){
			ll x=(a[i]-a[1])*i/2;
			ll y=m-x;
			if (y>=0&&y<mi){
				mi=y;
				s=i;
			}
		}
		cout<<s;
	}else{
		ll s=0,x;
		for (int i=1;i<=n;i++){
			s+=a[i];
		} 
		x=s/n;
		for (int i=1;i<=n;i++){
			if (a[i]<=x){
				b[i]=x-a[i];
			}else {
				b[i]=M;
			}
		}
		int i=1;
		sort(b+1,b+1+n);
		while (m>=b[i]){
			m-=b[i];
			i++;
			if (i>n){
				break;
			}
		}
		cout<<i-1;
	}
	return 0;
} 