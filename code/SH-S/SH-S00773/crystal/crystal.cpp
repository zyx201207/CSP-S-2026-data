/*
Oct31==Dec25?
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500009;
int n,m,a[N],s[N],ans;
int rd(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x;
}
int sum(int l,int r){
	return s[r]-s[l-1];
}
int check(int x){
	int l=1,r=x,mid,pos;
	while(l<=r){
		mid=(l+r)>>1;
		int temp=(x-mid+1)*a[x]-sum(mid,x);
		if (temp<=m){
			pos=x-mid+1;
			r=mid-1;
		}
		else l=mid+1;
//		cout<<x<<' '<<mid<<' '<<temp<<' '<<pos<<endl;
	}
	return pos;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	cout<<"AAA\n";
	for(int i=1;i<=n;i++) ans=max(ans,check(i));
	cout<<ans<<endl;
	return 0;
}
