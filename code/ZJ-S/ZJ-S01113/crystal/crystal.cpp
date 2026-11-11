#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
long long n,m,a[500010],l,r,mid,mi,ans,h,t,sum;
bool ch(long long x){
	h=1;sum=0;
	for(int i=1;i<=x-1;i++){
		sum+=a[i];
	}
	t=x;
	while(t<=n){
		sum+=a[t];
		if(a[t]*x-sum<=m){
			return 1;
		}
		sum-=a[h];
		h++;t++;
	}
	return 0;
}
int main(){
	fre();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1;r=n;ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(ch(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
