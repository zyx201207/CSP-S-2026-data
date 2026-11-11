#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500009],d[500009],s[500009],ans;
bool spA,spB;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
void solveA(){
	ll l=1,r=m;
	while(l<=r){
		ll mid=l+r>>1;
		if(mid*(mid+1)>m*2)r=mid;
		else l=mid+1;
	}
	cout<<l;
}
void solveB(){
	ll d=a[2]-a[1];
	ll l=1,r=m;
	while(l<=r){
		ll mid=l+r>>1;
		if(((mid-1)/d+1)*(mid+1)>m*2)r=mid;
		else l=mid+1;
	}
	cout<<l;
}
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	n=read(),m=read(),a[1]=read();
	for(ll i=2;i<=n;i++){
		a[i]=read();
		if(a[i]!=i)spA=0;
		if(a[i]-a[i-1]!=a[2]-a[1])spB=0;
	}
	if(spA)return solveA(),0;
	if(spB)return solveB(),0;
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++)d[i]=a[i+1]-a[i];
	d[n]=0;
	for(ll i=n;i>=1;i--)s[i]=s[i+1]+d[i];
	for(ll i=1;i<=n;i++){
		ll sum=0,j=i,t;
		while(sum<=m&&j>=1)sum+=s[j]-s[i],j--;
		if(sum>m)t=i-j-1;
		else t=i-j;
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}//75pts
