#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;cin >> n >> m;
	vector<long long>a(n+n);
	for(int i = 1;i <= n;++i){
		cin >>a[i];
	} 
	sort(a.begin()+1,a.end());
	vector<long long>dic(n+1);
	dic[0]=dic[1] = 0;
	for(int i = 2;i <= n;++i){
		long long t = a[i]-a[i-1];
		dic[i] = t;
	}
	long long ans = 1;
	for(long long i = 1;i <= n;++i){
		if(dic[i] > m)continue;
		long long sum = 0;
		for(long long j = i+1;j <= n;++j){
			sum += (j-i)*dic[j];
			if(sum == m)ans = max(ans,j-i+1*1LL);
			else if(sum > m)continue;
		}
	}
	cout << ans;
	return 0;
}
