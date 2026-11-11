#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;
typedef unsigned int uint;
typedef unsigned long long ull;
const int N=2e5+5;
int n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n];
	return 0;
} 
