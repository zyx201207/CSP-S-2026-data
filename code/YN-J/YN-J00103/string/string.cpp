#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node {
	int x;
	char c;
} a[N];
long long n,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i].x>>a[i].c;
	for(int i=1; i<=n/2; i++)
		if(a[i].c!=a[n-i+1].c) {
			if(a[i].x==a[n-i+1].x)
				ans+=a[i].x;
			else ans=abs(a[i].x-a[n-i+1].x)+1;
		}
	cout<<ans;
	return 0;
}
