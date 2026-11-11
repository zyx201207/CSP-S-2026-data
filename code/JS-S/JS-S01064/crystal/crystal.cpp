#include <bits/stdc++.h>
#define int long long 
#define N 1000100
using namespace std;

int n,m,t;
int a[N],aa[N],ans[N];


signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	int mm=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}

	sort(a+1,a+n+1);
	sort(aa+1,aa+n+1);

	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;

	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[1])
			t=1;
		else 
		{
			t=0;
			break;
		}
	}
	if(t==1)
	{
		cout<<n<<endl;
		return 0;
	}


	for(int i=n;i>=1;i--)
	{
		mm=m;
		for(int j=i;j>=1;j--)
		{
			if(mm>=aa[i]-aa[j])
			{
				mm-=aa[i]-aa[j];
			//	aa[j]=aa[i];
				ans[i]++;
				// for(int g=1;g<=n;g++)
				// 	cout<<aa[g]<<" ";
				// cout<<endl;
			}
			//cout<<endl;
			//if(mm<=0 || mm<aa[i]-aa[j])
			else
			{
				// for(int k=1;k<=n;k++)
				// {
				// 	cout<<aa[i]<<endl;	
				// 	if(aa[k]==a[i])
				// 		ans[i]++;
				// 	//cout<<aa[k]<<" ";
				// }
				// //cout<<endl;
				// //cout<<ans[i]<<endl;
				// for(int k=1;k<=n;k++)
				// {
				// 	aa[k]=a[k];
				// //	cout<<aa[k]<<" ";
				// }
				break;
			}
		}
	}

	sort(ans+1,ans+n+1);
	// for(int i=1;i<=n;i++)
	// 	cout<<ans[i]<<" ";
	// cout<<endl;
	cout<<ans[n]<<endl;

	return 0;
}