#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	unique(a+1,a+1+n);
	sort(a+1,a+1+n);
	int num=a[n];
	if(m>=2) cout << (a[n-m+2]&a[n-m+1]);
	else cout << a[n];
	return 0;
}
