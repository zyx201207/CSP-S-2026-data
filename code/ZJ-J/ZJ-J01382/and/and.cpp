#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[2][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k,sum=0;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[1][1]=a[1];
	b[1][0]=0;
	for(int i=2;i<=n;i++){
		b[(i&1)][0]=a[i];
		for(int j=1;j<=k;j++){
			b[(i&1)][j]=max(b[((i+1)&1)][j],((b[((i+1)&1)][j-1])&a[i]));
		}
	}
	cout<<b[(n&1)][k];
	return 0;
}