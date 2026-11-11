#include <iostream>
using namespace std;
int n,m,a[100005],b[100005],ans=1,c[100005];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<ans;k++)
			{
				if(b[k]==a[j])
				{
					ans=k;
					for(int q=k;q<=n;q++)
					{
						b[q]=0;
					}
				}
			}
			b[ans]=a[j];
			ans++;
		}
		for(int p=1;p<=m;p++)
		{
			for(int f=1;f<=n;f++)
			{
				if(b[f]==p)
				{
					c[p]++;
					break;
				}
			}
		}
		ans=1;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
