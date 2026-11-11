#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5;
int n;
long long m;
int a[N],b[N];
bool cmp(int x ,int y){
	return x<=y;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	long long ma=0;
	b[0]=0;
	b[1]=a[1]-a[0];
	for (int i=2;i<n;i++){
		b[i]=b[i-1]+2*(a[i]-a[i-1]);
	}
	for (int i=0;i<n;i++){
		long long ans =0;
		for (int j=0;j<n;j++){
			if (m>=b[j]-b[i])	ans = j-i+1;
		}
		ma=max(ma,ans);
	}
	cout <<ma;
	return 0;
}