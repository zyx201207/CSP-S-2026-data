#include <bits/stdc++.h>
using namespace std;
long long m,n,a[500064],a1[500064],num[500064],maxn=-64,cnt=0;
bool tp=0;
long long shu(long long start,long long m,long long x){
	m-=a1[start+x]*x;
	if(m<0||start+x>n){
		return x;
	}
	return shu(start,m,x+1);
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
		a1[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++){
		if(a1[i]==a1[i-1]){
			cnt++;
		} 
	}
	if(cnt==n-2){
		tp=1;
	}
	if(tp){
		for(int i=2;i<=n;i++){
			if((a1[2]+a1[2]*(i-1))*(i-1)/2>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		num[i]=shu(i,m,1);
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,num[i]);
	}
	cout<<maxn;
	return 0;
}