#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	
	sort(a+1,a+n+1,greater<int>());
	for(int j=1;j+m<=n;j++)
	{
		sum=a[j];
		for(int i=1;i<=m;i++)
	{
		sum&=a[i];
//		cout<<sum<<endl;
	}
	ans=max(ans,sum);
	}
	
	cout<<ans;
	return 0;
}
