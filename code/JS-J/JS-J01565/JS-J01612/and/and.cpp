#include <bits/stdc++.h>
using namespace std;


int a[100001];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	int n, m;
	cin >> n >> m;
	int maxn1 = 0;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] >= maxn1)
		{
			maxn1 = a[i];
		}
	}
	
	if(m == n)
	{	
		int t = 1;
		for(int i = 1;i <= n;i++)
		{
			t = (t & a[i]);
		}
		cout << t << endl;
	}
	else if(m ==1)
	{
		cout << maxn1 << endl;
	}
	else if(m == 2)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				if((a[i]&a[j])>= maxn && i != j)
				{
					maxn = (a[i]&a[j]);
					
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 3)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					if((a[i]&a[j]&a[k])>= maxn )
					{
						maxn = (a[i]&a[j]&a[k]);
					}
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 4)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					for(int p = k+1;p <= n;p++)
					{
						if((a[i]&a[j]&a[k]&a[p])>= maxn)
						{
							maxn = (a[i]&a[j]&a[k]&a[p]);
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 5)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					for(int p = k+1;p <= n;p++)
					{
						for(int f = p+1;f <= n;f++)
						{
							if((a[i]&a[j]&a[k]&a[p]&a[f])>= maxn)
							{
								maxn = (a[i]&a[j]&a[k]&a[p]&a[f]);
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 6)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					for(int p = k+1;p <= n;p++)
					{
						for(int f = p+1;f <= n;f++)
						{
							for(int q = f+1;q <= n;q++)
							{
								if((a[i]&a[j]&a[k]&a[p]&a[f]&a[q])>= maxn)
								{
									maxn = (a[i]&a[j]&a[k]&a[p]&a[f]&a[q]);
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 7)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					for(int p = k+1;p <= n;p++)
					{
						for(int f = p+1;f <= n;f++)
						{
							for(int q = f+1;q <= n;q++)
							{
								for(int u = q+1;u <= n;u++)
								{
									if((a[i]&a[j]&a[k]&a[p]&a[f]&a[q]&a[u])>= maxn)
									{
										maxn = (a[i]&a[j]&a[k]&a[p]&a[f]&a[q]&a[u]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	else if(m == 8)
	{
		int maxn = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					for(int p = k+1;p <= n;p++)
					{
						for(int f = p+1;f <= n;f++)
						{
							for(int q = f+1;q <= n;q++)
							{
								for(int u = q+1;u <= n;u++)
								{
									for(int m = u+1;m <= n;m++)
									{
										if((a[i]&a[j]&a[k]&a[p]&a[f]&a[q]&a[u]&a[m])> maxn)
										{
											maxn = (a[i]&a[j]&a[k]&a[p]&a[f]&a[q]&a[u]&a[m]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << maxn << endl;
	}
	
	return 0;
}



















