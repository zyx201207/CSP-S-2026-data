#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	int ans=a[0];
	for(long long i=1;i<m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
