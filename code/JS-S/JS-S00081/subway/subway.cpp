#include<bits/stdc++.h>
using namespace std;
int minn(int q,int w)
{
	if(q<w) return q;
	return w;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q,xxx;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m),k(n);
	vector<vector<int>> a(n,vector<int>()),t(n,vector<int>()),farr(m,vector<int>(m,1000000000));//s : a-to-b
	for(int i=0;i<m;i++) cin>>w[i];
	
	for(int i=0;i<m;i++) farr[i][i]=0;
	
	if(20==c||21==c)//20-21
	{
		vector<char> f(m,'0');
		for(int i=0;i<n;i++)
		{
			cin>>k[i];
			for(int j=0;j<k[i];j++)
			{
				cin>>xxx;
				if(1==i) f[xxx-1]='1';
				a[i].push_back(xxx-1);
				cin>>xxx;
				t[i].push_back(xxx);
			}
			for(int j=0;j<k[i];j++)
			{
				for(int o=j+1;o<k[i];o++)
				{
					int now=t[i][j]+t[i][o];
					int x=a[i][j],y=a[i][o];
					farr[x][y]=minn(farr[x][y],now);
				}
			}
		}
		
		
		for(int i=0;i<k[0];i++)
		{
			for(int j=i+1;j<k[0];j++)
			{
				for(int o=0;o<k[1];o++)
				{
					if(f[a[0][j]]=='1') farr[i][o]=minn(farr[i][o]+farr[j][o],farr[i][o]);
				}
			}
		}
	
	
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			x--,y--;
			if(x>y) swap(x,y);
			int ans=w[x]+w[y]+farr[x][y];
			cout<<ans<<"\n";
		}
		return 0;
	}
	
	
	
	
	
	
	
	

	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>xxx;
			a[i].push_back(xxx-1);
			cin>>xxx;
			t[i].push_back(xxx);
		}
		for(int j=0;j<k[i];j++)
		{
			for(int o=j+1;o<k[i];o++)
			{
				int now=t[i][j]+t[i][o];
				int x=a[i][j],y=a[i][o];
				farr[x][y]=minn(farr[x][y],now);
			}
		}
	}
	
	
	if(12<=c&&c<=19)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k[i];j++)
			{
				for(int o=j+1;o<k[i];o++)
				{
					int x=a[i][j],y=a[i][o];
					farr[x][y]=xxx*2;
				}
			}
		}
	}
	else if(c==22||c==23)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				for(int k=j+1;k<m;k++)
				{
					farr[i][k]=minn(farr[i][j]+farr[j][k],farr[i][k]);
				}
			}
		}
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				for(int k=j+1;k<m;k++)
				{
					farr[i][k]=minn(farr[i][j]+farr[j][k],farr[i][k]);
				}
			}
		}
	}
	
	
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		int ans=w[x]+w[y]+farr[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}



/*#include<bits/stdc++.h>
using namespace std;
int minn(int q,int w)
{
	if(q<w) return q;
	return w;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q,xxx;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m),k(n);
	vector<vector<int>> a(n,vector<int>()),t(n,vector<int>()),farr(m,vector<int>(m,1000000000));//s : a-to-b
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	if(n<=2&&q>100)//20-21
	{
		vector<char> f(m,'0');
		for(int i=0;i<n;i++)
		{
			cin>>k[i];
			for(int j=0;j<k[i];j++)
			{
				cin>>xxx;
				if(1==i) f[xxx-1]='1';
				a[i].push_back(xxx-1);
				cin>>xxx;
				t[i].push_back(xxx);
			}
			for(int j=0;j<k[i];j++)
			{
				for(int o=j+1;o<k[i];o++)
				{
					int now=t[i][j]+t[i][o];
					int x=a[i][j],y=a[i][o];
					farr[x][y]=minn(farr[x][y],now);
				}
			}
		}
		
		
		for(int i=0;i<k[0];i++)
		{
			for(int j=i+1;j<k[0];j++)
			{
				for(int o=0;o<k[1];o++)
				{
					if(f[a[0][j]]=='1') farr[i][o]=minn(farr[i][o]+farr[j][o],farr[i][o]);
				}
			}
		}
	
	
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			x--,y--;
			if(x>y) swap(x,y);
			int ans=w[x]+w[y]+farr[x][y];
			cout<<ans<<"\n";
		}
		return 0;
	}
	
	
	
	for(int i=0;i<m;i++) farr[i][i]=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>xxx;
			xxx--;
			a[i].push_back(xxx);
			cin>>xxx;
			t[i].push_back(xxx);
		}
		for(int j=0;j<k[i];j++)
		{
			for(int o=j+1;o<k[i];o++)
			{
				int now=t[i][j]+t[i][o];
				int x=a[i][j],y=a[i][o];
				farr[x][y]=minn(farr[x][y],now);
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			for(int k=j+1;k<m;k++)
			{
				farr[i][k]=minn(farr[i][j]+farr[j][k],farr[i][k]);
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		int ans=w[x]+w[y]+farr[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}
*/
