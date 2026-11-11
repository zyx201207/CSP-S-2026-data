#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=5e5+10;
ll a[N],s[N],c[N],m;
int n;

bool check(int mid){
	ll mi=5e18;
	for(int i=mid;i<=n;i++){
		int i1=i-mid;
		ll num1=((ll)(i1))*((ll)(a[i]-a[i1]));
		num1+=c[i1];
		num1=c[i]-num1;
		mi=min(mi,num1);
	}
	return mi<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	s[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		ll num1=s[i]*(ll)(i-1);
		num1+=c[i-1];
		c[i]=num1;
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",r);
	return 0;
}