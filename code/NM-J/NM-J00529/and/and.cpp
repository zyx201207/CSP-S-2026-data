#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(m==1) cout<<a[1];
	ans=a[1];
	for(int i=1;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
