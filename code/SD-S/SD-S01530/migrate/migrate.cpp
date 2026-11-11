#include <bits/stdc++.h>
using namespace std;

const int N=2000200;
int n,c,t,d,a[N],b[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]-a[i]>d && a[j]-a[i]<2*d && j-i==3)
				{
					ans++;
				}
			}
		} 
		cout<<ans;
	}
	return 0; 
}
