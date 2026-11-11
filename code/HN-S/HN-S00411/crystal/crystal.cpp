#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],b[N],sum=-1;
bool f1=1,f2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f1=0;
		}
	}
	sort(a+1,a+1+n);
	ll x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			f2=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	if(f1==1){
		ll k=1,cnt=0;
		while(cnt<=m){
			cnt+=k;
			k++;
		}
		cout<<k-1;
		return 0;
	}
	else if(f2==1){
		ll k=1,cnt=0;
		while(cnt<=m){
			cnt+=(k*x);
			k++;
		}
		cout<<k-1;
		return 0;
	}
	else{
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				if((b[j-1]-b[i-1]+m)<a[j]*(j-i)){
					continue;
				}
				sum=max(sum,j-i+1);
			}
		}
		cout<<sum;
	}	
	return 0;
}
