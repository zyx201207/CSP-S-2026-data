#include <bits/stdc++.h>
using namespace std;
int c,q,n,sum;
long long int d,a[2000000];
void asd(){
	cin>>n>>d;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-3;i++)
	{
		if((a[i+2]-a[i])<=d&&(a[i+1]-a[i])<=d&&(a[i+3]-a[i+1])<=d&&(a[i+3]-a[i+2])<=d&&(a[i+3]-a[i])>d) {
			sum++;
		}
	}
	cout<<sum;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migarate.out","w",stdout);
	cin>>c>>q;
	for(int i=1;i<=q;i++) asd();
	return 0;
}
