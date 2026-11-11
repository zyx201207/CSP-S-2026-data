#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	int ma=0;
	int kg=1;
	int s=0;
	int san=0;
	int kgg=1;
	cin>>n>>m;
	int a[n+5];
	int b[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j]-a[i];
			if(b[j]>0)
			{
				b[j]=(m*-1)-1;
			}
		}
		for(int w=1;w<=n;w++)
		{
			if(w==n&&b[w]==0)
			{
				if(ma*-1<=m)
				{
							m-=ma*-1;
							for(int q=1;q<=n;q++)
							{
								if(b[q]==ma)
								{
									b[q]=0;
									break;
								}
							}
							if(m>=0)w=1;
							kg=1;
				}			
							
			}
			if(b[w]!=0)
			{
				
				if(kg==1)
				{
					kg=0; 
					ma=b[w];
				}
				if(kg!=1||w==n)
				{
					if(b[w]>ma)
					{
						ma=b[w];
					}
					if(w==n)
					{
						if(m>=ma*-1)
						{
							m-=ma*-1;
							for(int q=1;q<=n;q++)
							{
								if(b[q]==ma)
								{
									b[q]=0;
									break;
								}
							}
							if(m>0)w=1;
							kg=1;
							
						}
					}
					
				}

			}
		}
		for(int u=1;u<=n;u++)
		{
			if(b[u]==0)
			{
				s+=1;
			}
		}
		
		if(kgg==1)
		{
			kgg=0;
			san=s;
		}
		if(s>san)
		{
			san=s;
		}
		s=0;
	}
	
	cout<<san<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
