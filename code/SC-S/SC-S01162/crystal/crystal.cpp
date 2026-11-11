#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],c[500005];
unsigned long long m,sf[500005],ma=1,x;
void read(ll &a){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	a=x*f;
}
bool ck(int mid,int k){
	unsigned long long sff=sf[mid]-sf[k-1]-c[mid]*(mid-k+1);
	if(sff<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[n]-a[i];
		sf[i]=sf[i-1]+c[i];
	}
	for(int k=1;k<=n;k++){
		int i,l=k,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ck(mid,k)){
				l=mid+1;
				i=mid;
			}
			else{
				r=mid-1;
			}
		}
		x=i-k+1;
		ma=max(ma,x);
		x=n;
		if(k+ma>=x){
			break;
		}
	}
	cout<<ma;
	return 0;
}
