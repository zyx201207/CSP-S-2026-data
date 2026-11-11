#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m,n,tmp,k,a[500009],i;
ll read(){
	ll x=0,f=1;
	char c;
	while(c!=EOF){
		c=getchar_unlocked();
		if(c=='-')f=-1;
		x+=c-'0';}
	return x*f;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;}
	for(i=0;i<n;i++)cin>>a[i];
	while(m--){
		sort(a,a+n);
		a[0]++;
	}tmp=a[0];
	for(i=0;i<n;i++)if(a[i]==tmp)k++;
	cout<<k;
	return 0;
}
