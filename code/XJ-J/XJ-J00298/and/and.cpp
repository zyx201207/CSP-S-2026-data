#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> x;
bool cmp(int x,int y){
	if (x>y){
		return x>y;
	}
}
int as(int x){
	int y=0;
	while (x!=0){
		y=y*10+x%2;
		x = x/2;
	}
	return y;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin >> n>>m;
	for (int i = 1;i<=n;i++) cin >> a[i];
	sort(a.begin(),a.end(),cmp);
	for (int i = 1;i<=m;i++){
		x[i] = as(a[i]);
	}
	int cnt = 0;
	for (int i = m;i>=1;i--){
		cnt += x[i] and x[i-1];
	}
	cout<<cnt;
}