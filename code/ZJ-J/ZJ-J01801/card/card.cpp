#include <bits/stdc++.h>
using namespace std;
deque <int> d;
int tot[3005];
int a[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool f=false;
			int w=-1;
			for(int k=0;k<d.size();k++)
			{
				if(d[k]==a[j])
				{
					 f=true;
					 w=k;
					 break;
				}
			}
			if(f) w=d.size()-w;
			//cout<<w<<" ";
			if(f)
			{
				for(int k=1;k<=w;k++)
					d.pop_back();
			}
			d.push_back(a[j]);
		}
		//cout<<endl;
		for(int j=0;j<d.size();j++)
		{
			tot[d[j]]++;
		}
		while(!d.empty())
		{
			d.pop_back();
		}
	}
	for(int i=1;i<=m;i++) cout<<tot[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}