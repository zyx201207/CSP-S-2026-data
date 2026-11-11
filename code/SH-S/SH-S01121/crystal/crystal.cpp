#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll sum[N];
int maxx;
bool check(int l,int r){
	ll lm=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
	return lm<=m;
}
int so(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,x)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return x-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,so(i));
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
