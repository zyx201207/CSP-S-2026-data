#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
const int N=2e5+100;
ll a[N];
char c[N];
char l,r;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll lst=0,rst=0;
	int i=0,j=n+1;
	while (i<=j){
		ll k,a1,a2;
		char c1,c2;
		a1=lst;a2=rst;
		if (a1==0){
			a1=a[++i];
			c1=c[i];
		}
		else{
			c1=l;
		}
		if (a2==0){
			a2=a[--j];
			c2=c[j];
		}
		else{
			c2=r;
		}
		if (i>j){
			break;
		}
		k=abs(a1-a2);
		if (a1>a2){
			lst=k;
			l=c1;
			rst=0;
		}
		else if (a1<a2){
			rst=k;
			r=c2;
			lst=0;
		}
		else{
			rst=lst=0;
		}
		if (c1!=c2){
			ans+=min(a1,a2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
