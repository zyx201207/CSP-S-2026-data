#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll const N=1e6+10;
ll n,a[N],c=0,sum,x,Max=0,Min=0;
string  s,b,b1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		Max=max(a[i],Max);
	}
	for(ll j=Max;j>=1;j--){
		x=0;
		for(int i=1;i<=n;i++){
			if(a[i]%j==0)x++;
		}
		if(x==n){
			Min=max(j,Min);
			break;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]/=Min;
		for(int j=1;j<=a[i];j++){
			b[c++]=s[i];
		}
		sum+=a[i];
	}
	c=0;
	for(int i=sum-1;i>=0;i--){
		b1[c++]=b[i];
	}
	c=0;
	for(int i=0;i<sum/2;i++){
		if(b[i]!=b1[i])c++;
	}
	cout<<c*Min;
	return 0;
}
