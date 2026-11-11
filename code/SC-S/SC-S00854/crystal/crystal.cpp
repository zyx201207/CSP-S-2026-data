#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i]-a[i-1];
		if(i>2&&c[i]!=c[i-1]) fl=0;
	}
	if(fl==1){
		int tnt=m/c[2],ans=0,i=1;
		while(tnt>=ans&&i<=n){
			ans+=i;
			i++;
		}
		cout<<i-1;
		return 0;
	}
//	ll mx=-1e12-5,ansmx=1;
//	for(ll i=a[1];i<=a[n];i++){
//		ll as[N];
//		for(ll j=1;j<=n;j++){
//			as[j]=a[j]-i;
//			if(as[j]<0) as[j]=mx;
//		}
//		sort(as+1,as+1+n);
//		ll ans=0,j=1;
//		while(m>=ans&&j<=n){
//			ans+=j;
//			j++;
//		}
//		ansmx=max(ansmx,j);
//	}
	return 0;
}
//30
//不理解，去掉注释符就输入不了？