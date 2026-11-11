#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int NM = 5e5;
ll A[NM+4];
int n,ans;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>A[i];
	sort(A+1,A+1+n);
	for(int i = n;i >= 1;i--){
		if(i < ans) break;
		ll ml = m;
		int sum = 1;
		for(int j = i-1;j >= 1;j--){
			if(A[j]+ml < A[i]) break;
			ml -= (A[i]-A[j]);
			sum++;
		}
		ans = max(ans,sum);
	}
	cout<<ans;
	return 0;
}
