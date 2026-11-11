#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long num[200005];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= m - 1;i++){
		a[i] = a[i] & a[i + 1];
	}
	cout << a[m];
} 
