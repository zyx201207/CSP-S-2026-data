#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,fans = 0;
	cin>>n>>m;
	vector<int> A(n);
	for (int &a : A) cin>>a;
	sort(A.begin(),A.end());
	for (int i = 0;i < n;i++){
		long long ans = 0,a = m;
		for (int j = i;j >= 0 && a >= 0;j--){
			a -= A[i] - A[j];
			ans++;
		}
		if (a < 0) fans = max(fans,ans - 1);
		else fans = max(fans,ans);
	}
	cout<<fans;
	return 0;
}