#include<bits/stdc++.h>

using namespace std;

const int MAXN=5e5+10;

long long n,a[MAXN],dp[MAXN],l,r,m;

bool cmp(long long xkk,long long ykk){

	return xkk<ykk;

}

bool check(long long xkk){

	for(long long i=1;i<=n-xkk+1;i++){

		long long lx=i;

		long long rx=i+xkk-1;

		long long tk=dp[rx]-dp[lx-1];

		if(abs(a[rx]*xkk-tk)<=m){

			return true;

		}

	}

	return false;

}

bool flag=0;

int main(){

	freopen("crystal.in","r",stdin);

	freopen("crystal.out","w",stdout);

	cin>>n>>m;

	for(long long i=1;i<=n;i++){

		cin>>a[i];

		if(a[i]!=a[i-1])flag=true;

	}

	if(!flag){

		cout<<n;

		return 0;

		}

	sort(a+1,a+n+1,cmp);

	for(long long i=1;i<=n;i++){

		dp[i]=dp[i-1]+a[i];

	}

	l=1;

	r=n;

	while(l<r){

		long long mid=((l+r)>>1);

		if(check(mid)){

			l=mid+1;

		}else{

			r=mid;

		}		

	}

	cout<<l-1;

	return 0;

}

/*

5 5

1 2 4 8 9





5 8

-3 -1 2 2 7



*/


