#include<bits/stdc++.h>
using namespace std;
long long d[500005];
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int l=1,r=2;
	int cur=1;
	long long res=0;
	long long rs=0;
	while(r<=n){
		while(r<=n&&res+cur*d[r]<=m){
			res+=cur*d[r];
			rs+=d[r];
			cur++;
			r++;
		}
		if(r>n)break;
		res+=cur*d[r];
		rs+=d[r];
		res-=rs;
		rs-=d[l+1];
		l++;
		r++;
	}
	cout<<cur;
	return 0;
}
