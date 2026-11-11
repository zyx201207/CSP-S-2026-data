#include<bits/stdc++.h>
using namespace std;

const int N=2e5+3;
int a[N];
unsigned long long ans=0;
unsigned long long n,m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n==m) {
		ans+=a[1];
		for(int i=2; i<=n; i++) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);       
	fclose(stdout);

	return 0;
}
