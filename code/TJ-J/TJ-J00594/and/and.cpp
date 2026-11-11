#include<bits/stdc++.h>
using namespace std;
int number[200005] ;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>number[i];
	}
	if(m==1||m>2)
	{
		int maxnu=0;
		for(int i=0;i<n;i++)
		{
			if(maxnu<number[i])
			{
				maxnu=number[i];
			}
		}
		cout<<maxnu;
		return 0;
	}
	else
	{
		int endand;
		for(int i=0;i<n;i++)
		{
			int t1len=0;
			bool two1[1005];
			int number1=number[i];
			for(int j=0;number1>0;j++)
			{
				two1[j]=number1%2;
				number1/2;
				t1len+=1;
			}
			for(int j=i+1;j<n;j++)
			{
				int t2len=0;
				bool two2[1005],twoand[1005];
				int tenand;
				int number2=number[j];
				for(int k=0;number2>0;k++)
				{
					two2[k]=number2%2;
					number2/2;
					t2len+=1;
				}
				int tandlen=0;
				for(int k=max(t1len,t2len);k>=0;k--)
				{
					if(two1[k]==two2[k])
					{
						twoand[tandlen]=1;
						tandlen+=1;
					}
					else
					{
						tandlen+=1;
					}
				}
				for(int k=max(t1len,t2len);k>=0;k--)
				{
					tenand+=twoand[k]*pow(2,k);
				}
				if(tenand>endand)
				{
					endand=tenand;
				}
			}
		}
		cout<<endand;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
