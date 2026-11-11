#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[1000005];
bool ff(int x,int y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,ff);
	ans=a[m];
	cout<<ans;
	return 0;
}
