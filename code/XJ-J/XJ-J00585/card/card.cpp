#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[300010];
bool s[300010];
stack<long long> b;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) sum[j]=0;
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++)
			sum[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
