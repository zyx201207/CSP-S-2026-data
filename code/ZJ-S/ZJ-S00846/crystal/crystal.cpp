#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
long long check(long long x){
	long long aa=0;
	long long pm=m;
	for(int i=n;i>=1;i--){
		if(a[i]<=x){
			long long cha=x-a[i];
			if(pm>=cha){
				pm-=cha;
				aa++;
			}
		}
	}
	return aa;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long ma=-1;
	int f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f1=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f2=0;
		}
		ma=max(ma,abs(a[i]));
	}
	sort(a+1,a+1+n);
	if(f1==1){
		cout<<check(a[n]);
		return 0;
	}
	else if(f2==1){
		cout<<check(a[n]);
		return 0;
	}
	long long maa=LLONG_MIN;
	if(ma<=1e5){
		for(int i=-ma;i<=ma;i++){
			maa=max(maa,check(i));
		}
		cout<<maa;
		return 0;
	}
	return 0;
}
