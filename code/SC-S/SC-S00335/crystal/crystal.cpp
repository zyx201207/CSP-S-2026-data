#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];

bool check(long long k){
	long long ans=9999999999;
	for(int i=1;i<=n-k+1;i++){
		long long num=0;
		for(int j=i;j<=i+k-1;j++){
			num+=(a[i+k-1]-a[j]);
		}
		ans=min(ans,num);
	}
	return ans<=m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)	A=0;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])	B=0;
		}
	}
	if(A){
		long long r=1;
		for(r=1;r<=n;r++){
			if((r+1)*r>m*2)	break;
		}
		cout<<r;
		return 0;
	}
	else if(B){
		long long er=a[2]-a[1];
		long long r=1;
		for(r=1;r<=n;r++){
			if((er+(r-1)*er)*r>2*m)	break;
		}
		cout<<r;
		return 0;
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))	l=mid+1;
		else	r=mid-1;
	}
	cout<<r;
	return 0;
}