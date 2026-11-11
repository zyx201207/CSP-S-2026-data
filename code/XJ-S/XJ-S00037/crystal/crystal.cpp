#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		while(a[i]!=a[i+1]&&m>0){
			m--;
			a[i]++;
		}
	}
	int start=n-1;
	int maxn=-1;
	for(int i=n-1;i>=0;i--){
		int cnt=1;
		while(a[start]==a[i]&&i>=0){
			cnt++;
			i--;
		}
		start=i;
		maxn=max(cnt,maxn);
	}
	cout << maxn;
	return 0;
}
