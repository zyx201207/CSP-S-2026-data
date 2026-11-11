#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500003];
int ch(long long x){
	int ll=1,rr=n;
	bool f=0;
	long long nm=m;
	while(ll<rr){
		int md=(ll+rr+1)/2;
		if(a[md]>x)rr=md-1;
		else{
			ll=md;
			f=1;
		}
	}
	if(!f)return 0;
	for(int i=ll;i>=1;i--){
		if(nm>=x-a[i])nm-=x-a[i];
		else{return ll-i;}
	}
	return ll;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=max(ans,ch(a[i]));
	}
	cout<<ans;
	return 0;
}
