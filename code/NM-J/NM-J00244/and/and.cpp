//按位与是啥来着╥﹏╥...
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ma;
//void dfs(int x)
//{
//	
//} 

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	if(m==1)
	{
		sort(a.begin(),a.end());
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		} 
		cout<<ans<<endl;
		return 0;
	}
	
	//cout<<ans<<endl;
    return 0;
    
}
