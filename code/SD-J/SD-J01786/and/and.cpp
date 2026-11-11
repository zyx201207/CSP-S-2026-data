#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500000];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int v=a[i];
		for(int j=i;j<=i+m-1;j++)
		{
			v&=a[j];
			//cout<<v<<' '<<a[j]<<' '<<j<<endl;
		}
		ans=max(ans,v);
	}
	cout<<ans;
	return 0;
}
