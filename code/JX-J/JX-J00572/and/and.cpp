#include<bits/stdc++.h>

#define ll long long

using namespace std;

// oh my gosh, its DP. god damn.

unsigned ll dp[2][100005],in;
int n,m;
unsigned ll maxn=-2147483647;

const unsigned ll p=0xffffffff;

vector<unsigned ll> a;

int solve(){

	int ret;

	dp[0][0]=p;
	dp[1][0]=p;

	for(int q=1;q<=n;q++){

		

		swap(dp[0],dp[1]);

		for(int j=1;j<=min(q,m);j++){
			dp[1][j]=max(
				(dp[1][j-1] & a[q-1]),
				dp[0][j]
			);

		}

	}

	return dp[1][m];
}

bool cmp(unsigned ll &l,unsigned ll &r){
	return l>r;
}

int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	//---input---
	
	cin>>n>>m;
	for(int _=0;_<n;++_){

		cin>>in;

		a.push_back(in);
	}

	sort(a.begin(),a.end(),cmp);

	//---solve---

	cout<<solve()<<'\n';

	return 0;
}