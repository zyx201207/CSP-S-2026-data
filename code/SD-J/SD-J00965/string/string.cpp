#include<bits/stdc++.h>
using namespace std;
int n;
struct A
{
	long long  h;
	string f;
}a[100050],c[100050],d[100050];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].h>>a[i].f;
		sum+=a[i].h;
	}
	if (sum%2==1)
	{
		sum=sum/2+1;
		int j=0;
		for (int i=1;i<=n;i++)
		{
			if (sum==0)
			{
				j=i;
				break;
			}
			if (sum>=a[i].h)
			{
				sum-=a[i].h;
				c[i].h=a[i].h;
				c[i].f=a[i].f;
			}
			else
			{
				c[i].h=sum-1;
				c[i].f=a[i].f;
				a[n+1].h=a[i].h-sum;
				a[n+1].f=a[i].f;
				sum=0;
			}
		}
		d[1].h=a[n+1].h;
		d[1].f=a[n+1].f;
		int k=2;
		for (int i=j;i<=n;i++)
		{
			d[k].h=a[i].h;
			d[k].f=a[i].f;
			k++;
		}
		j--;
		/*for (int i=1;i<=j;i++)
		{
			cout<<c[i].h<<" "<<c[i].f<<endl;
		}*/
		k--;
		int num=0,gg=0;
		string s;
		for  (int i=1;i<=j;i++)
		{
			if (num!=0)
			{
				if (c[i].h<=num)
				{
					if (c[i].f==s)
					{
						num=num-c[i].h;
						continue;
						
					}
					else
					{
						num=num-c[i].h;
						gg+=c[i].h;
						continue;
					}
				}
				else
				{
					if (c[i].f==s)
					{
						c[i].h-=num;
						k--;
						
						
					}
					else
					{
						c[i].h-=num;
						gg+=num;
						k--;
					}
				}
			}
				
			
			
			if (c[i].h<=d[k].h)
			{
				if (c[i].f==d[k].f)
				{
					num=d[k].h-c[i].h;
					s=d[k].f;
					
				}
				else
				{
					num=d[k].h-c[i].h;
					s=d[k].f;
					gg+=c[i].h;
				}
			}
			else
			{
				for (int i=1;i<=j;i++)
				{
					if (c[i].h<=d[k].h)
					{
						if (c[i].f==d[k].f)
						{
							num=d[k].h-c[i].h;
							s=d[k].f;
						}
						else
						{
							num=d[k].h-c[i].h;
							s=d[k].f;
							
							gg+=c[i].h;
						}
					}
					else
					{
						while ((c[i].h>=d[k].h)&&k>=1)
						{
							
							if (c[i].f==d[k].f)
							{
								c[i].h-=d[i].h;
								k--;
								
							}
							else
							{
								c[i].h-=d[i].h;
								gg+=d[i].h;
								k--;
							}
						}
							
					}
				}
				
			}
			
		}
		cout<<gg;
	}
	
	
	else
	{
		sum=sum/2;
		int j=0;
		for (int i=1;i<=n;i++)
		{
			if (sum==0)
			{
				j=i;
				break;
			}
			if (sum>=a[i].h)
			{
				sum-=a[i].h;
				c[i].h=a[i].h;
				c[i].f=a[i].f;
			}
			else
			{
				c[i].h=sum-1;
				c[i].f=a[i].f;
				a[n+1].h=a[i].h-sum+1;
				a[n+1].f=a[i].f;
				sum=0;
			}
		}
		d[1].h=a[n+1].h;
		d[1].f=a[n+1].f;
		int k=2;
		for (int i=j;i<=n;i++)
		{
			d[k].h=a[i].h;
			d[k].f=a[i].f;
			k++;
		}
		j--;
		k--;
		long long num=0,gg=0;
		string s;
		for  (int i=1;i<=j;i++)
		{
			if (num!=0)
			{
				if (c[i].h<=num)
				{
					if (c[i].f==s)
					{
						num=num-c[i].h;
						continue;
						
					}
					else
					{
						num=num-c[i].h;
						gg+=c[i].h;
						continue;
					}
				}
				else
				{
					if (c[i].f==s)
					{
						c[i].h-=num;
						k--;
						
						
					}
					else
					{
						c[i].h-=num;
						gg+=num;
						k--;
					}
				}
			}
				
			
			
			if (c[i].h<=d[k].h)
			{
				if (c[i].f==d[k].f)
				{
					num=d[k].h-c[i].h;
					s=d[k].f;
					
				}
				else
				{
					num=d[k].h-c[i].h;
					s=d[k].f;
					gg+=c[i].h;
				}
			}
			else
			{
				for (int i=1;i<=j;i++)
				{
					if (c[i].h<=d[k].h)
					{
						if (c[i].f==d[k].f)
						{
							num=d[k].h-c[i].h;
							s=d[k].f;
						}
						else
						{
							num=d[k].h-c[i].h;
							s=d[k].f;
							
							gg+=c[i].h;
						}
					}
					else
					{
						while ((c[i].h>=d[k].h)&&k>=1)
						{
							
							if (c[i].f==d[k].f)
							{
								c[i].h-=d[i].h;
								k--;
								
							}
							else
							{
								c[i].h-=d[i].h;
								gg+=d[i].h;
								k--;
							}
						}
							
					}
				}
				
			}
			
		}
		cout<<gg;
	}
	
}
