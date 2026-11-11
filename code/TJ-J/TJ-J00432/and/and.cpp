#include<bits/stdc++.h>
using namespace std;
int n,m, a[200005],ans[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int num;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]<a[i])
		{
			ans[i]=a[i];
			num=i;
		}
	}
	a[num]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[j])
			{
			
			if(ans[i]<ans[i-1]&a[j])
			  {
				ans[i]=ans[i-1]&a[j];
			  }
		    }
		}
		a[num]=0;
		cout<<ans[i];
	}
	return 0;
	
}
