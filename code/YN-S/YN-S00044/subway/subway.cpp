#include <iostream>
#include <vector>
using namespace std;
long long c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c>>n>>m>>d>>q;
	vector<long long> biaoji(m + 1);
	vector<long long> w(m + 1);
	vector<long long> v(m + 1);
	vector<long long> v2(m + 1);
	vector<long long> tip(m + 1);
	for(long long i = 1;i <= m;i++)
	{
		v2[i] = 0;
		biaoji[i] = 0;
		v[i] = 0;
		tip[i] = 0;
		cin>>w[i];//口→厅
	}
	for(long long i = 1;i <= n;i++)
	{
		long long x;
		cin>>x;
		
		for(long long j = 1;j <= x;j++)
		{
			cin>>biaoji[j];
			if(tip[biaoji[j]] == 1)
			{
				tip[biaoji[j]] = 9178;
			}
			tip[biaoji[j]] = i;
		}
		if(i == 1)
		{
			for(long long j = 1;j <= x;j++)
			{
				cin>>v[biaoji[j]];
			}
		}
		else
		{
			for(long long j = 1;j <= x;j++)
			{
				cin>>v2[biaoji[j]];
			}
		}
	}
	for(int i = 1;i <= 3;i++)
	{
		cout<<v[biaoji[i]]<<" ";
	}
	for(int i = 1;i <= 3;i++)
	{
		cout<<v2[biaoji[i]]<<" ";
	}
	long long travel = 0;
	bool panduan = false;
	int zhenjia = 0;
	while(q--)
	{
		long long l,r; 
	    cin>>l>>r;
		if(tip[biaoji[l]] == 9178)
		{
			if(v[biaoji[l]] < v2[biaoji[l]])
			{
				travel += v[biaoji[l]] + w[l];
				zhenjia = 1;
			}
		}
		else
		{
			if(tip[biaoji[l]] != 1)
			{
				travel += v2[biaoji[l]] + w[l];
				zhenjia = 2;
			}
			else
			{
				travel += v[biaoji[l]] + w[l];
				zhenjia = 1;
			}
		}
		if(zhenjia == 1)
		{
			for(int i = l + 1;i;i++)
			{
				if(tip[biaoji[i]] == tip[biaoji[r]])
				{
					travel += v[biaoji[i]] + w[i];
					panduan = true;
					break;
				}
				if(tip[biaoji[i]] != 9178)
				{
					travel += v[biaoji[i]];
				}
				else
				{
					if(tip[biaoji[r]] != 1)
					{
						travel += v[biaoji[i]] + w[i] + v2[biaoji[i]];
						for(int j = l + 1;j;j++)
						{
							if(tip[biaoji[j]] == tip[biaoji[r]])
							{
								travel += v2[biaoji[j]] + w[i];
								panduan = true;
								break;
							}
							if(tip[biaoji[i]] != 9178)
							{
								travel += v2[biaoji[i]];
							}
						}
					}
				}
				
			}
			if(panduan == true)
			{
				cout<<travel<<'\n';
				travel = 0;
		    	continue;
	    	}
		}
		else
		{
			for(int i = l + 1;i;i++)
			{
				if(tip[biaoji[i]] == tip[biaoji[r]])
				{
					travel += v2[biaoji[i]] + w[i];
					panduan = true;
					break;
				}
				if(tip[biaoji[i]] != 9178)
				{
					travel += v2[biaoji[i]];
				}
				else
				{
					if(tip[biaoji[r]] == 1)
					{
						travel += v[biaoji[i]] + w[i] + v2[biaoji[i]];
						for(int j = l + 1;j;j++)
						{
							if(tip[biaoji[j]] == tip[biaoji[r]])
							{
								travel += v[biaoji[j]] + w[i];
								panduan = true;
								break;
							}
							if(tip[biaoji[i]] != 9178)
							{
								travel += v[biaoji[i]];
							}
						}
					}
				}
				
			}
			if(panduan == true)
			{
				cout<<travel<<'\n';
				travel = 0;
				continue;
			}
		}
	}
	return 0;
}
