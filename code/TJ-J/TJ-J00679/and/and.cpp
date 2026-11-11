#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	unsigned long long sum=a[1];
	for(int i=2;i<=m;i++)
	{
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
