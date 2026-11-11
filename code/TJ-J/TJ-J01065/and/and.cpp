#include <bits/stdc++.h>

using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,x;
	cin >> n >> x;
	vector<int> a(n);
	
	for (long long i=0;i<n;i++){
		cin >> a[i];
		
	}
	sort(a.begin(),a.end(),greater<long long>());
	
	cout << a[x-1];
	return 0;
}
