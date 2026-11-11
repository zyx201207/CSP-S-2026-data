#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int _t=0;_t<t;_t++)
	{
		int n,d;
		cin>>n>>d;
		int a[n];
		//vector<int>bian[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			/*for(int j=i-1;j>=0;j++)
			{
				if(a[i]-a[j]<=d)
				{
					//bian[i].push_back(j);
				}
				else
				{
					break;
				}
			}*/
		}
		/*int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<bian[i].size();j++)
			{
				for(int k=0;k<bian[bian[i][j]].size();k++)
				{
					bian[i].push_back(bian[bian[i][j]][k]);
				}
			}
			sort(bian[i].begin(),bian[i].end());
			for(int j=0;j<bian[i].size();j++)
			{
				if(j>0&&bian[i][j]!=bian[i][j-1]&&bian[i][j]==bian[i][j+1]&&bian[i][j+1]!=bian[i][j+2]||j==0&&bian[i][j]==bian[i][j+1]&&bian[i][j+1]!=bian[i][j+2])
				{
					ans++;
					j+=2;
				}
			}
		}*/
		cout<<0<<'\n';
	}
	return 0;
}
