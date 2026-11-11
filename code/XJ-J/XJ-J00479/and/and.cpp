#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int sum[200010];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout << (a[1]&a[2]);
	return 0;
	
}