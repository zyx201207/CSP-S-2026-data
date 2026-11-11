#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int t = n-m+1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[t];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
