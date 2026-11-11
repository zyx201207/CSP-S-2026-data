#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 2e5+10;
ll n,m; 
ll a[MAXN];
ll maxnn = -1;
bool used[MAXN];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	} 
	if(m==1) {
		cout<<a[1]; 
		exit(0);
	}
	sort(a+1,a+n+1);
	cout<<a[n-m];
	return 0;
}


