#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int sum=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}
