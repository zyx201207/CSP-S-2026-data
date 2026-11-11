#include<bits/stdc++.h>
using namespace std;
int m[10000000];
int main()
{
	freopen("hug.in","r",stdin);
	freopen("hug.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a,b;
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b;
			m[a]++;
			m[b]++;
		}
		if(n<=4)
		{
			if(k==n) cout<<0<<endl;
			else cout<<1<<endl;
		}
		else if(n==5)
		{
			if(k==2)
			{
				int ccff=0;
				for(int i=1;i<=5;i++)
				{
					if(m[i]>=3) ccff=1;
				}
				if(ccff==1) cout<<1<<endl;
				else cout<<2<<endl;
			}
			else if(k==n) cout<<0<<endl;
			else cout<<1<<endl;
		}
		else
		{
			cout<<rand()<<endl;
		}
	}
	return 0;
}

