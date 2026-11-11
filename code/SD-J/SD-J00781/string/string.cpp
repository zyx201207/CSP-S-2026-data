#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin >> n;
	string s;
	vector<long long> a(n);
	vector<char> c(n);
	for (int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	long long ans=0;
	int left=0, right=n-1;
	while (left<right){
		if (c[left]!=c[right]) ans+=min(a[left],a[right]);
		if (a[left]<a[right]){
			a[right]-=a[left];
			a[left]=0;
		}
		else {
			a[left]-=a[right];
			a[right]=0;
		}
		if (!a[left]) left++;
		if (!a[right]) right--;
	}
	cout << ans << '\n';
	return 0;
}
