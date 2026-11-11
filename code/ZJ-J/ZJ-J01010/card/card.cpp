#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[300030];
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=m;i++)
		b[i]=i;
	for(long long i=2;i<=n;i++)
		if(a[i]==a[i-1])
			for(long long j=a[i];j<=m;j++)
				b[j]++;
	for(long long i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
