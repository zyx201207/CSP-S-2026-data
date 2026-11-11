#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long l,r,a[500010],mid;
bool check(long long num){
	long long t=0;int lans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<num)(t+=num-a[i],lans++,0);
		if(a[i]==num)(lans++,0);
		if(t>m)return 0;
	}
	ans=lans;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=1e12+10;
	r=-1e12-10;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){l=min(a[i],l),r=max(a[i],r);}
	while(l<r){
		mid=(l-r)/2+r;
		if(check(mid)){l=mid;}else{r=mid-1;}
	}
	cout<<ans;
	return 0;
}