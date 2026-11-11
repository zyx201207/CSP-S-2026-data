#include<iostream>
#include<stack>
using namespace std;
const int N=1e6+10;
int a[N];
int tong[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	stack<int> q; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=n;
	while(t--)
	{
		for(int i=n-t+1;i<=n;i++)
		{
			q.push(a[i]);
			for(int j=n-t+1;j<=n;j++)
			{
				if(a[i]==a[j])
				{
					while(j!=i)
					{
						q.pop();
						j--;
					}
				}
			}
			
			while(!q.empty())
			{
				tong[q.top()]++;
				q.pop();
			}	
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}
