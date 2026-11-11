#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	stand<int>s;
	int v,m;
	freopen("cord.in","r",stdin);
	freopen("cord.out","w",stdout);
	cin>>v>>m;
	for(int i=v;i>0;i--)
	{
		n+=v;
	}
	int b[n];
	int a[n];
	int f;
	int d=0;
	cin>>f;
	b[0]=f;
	for(int i=1;i<n;i++)
	{
		int z;
		cin>>z;
		b[i]=z;
		for(int j=0;j<i;j++)
		{
			int r=n-1;
			b[i+r]=z;
			r--;	
		}
	}
	for(int i=0;i<n;i++)
	{
		int o=0;
		
		for(int j=0;i<d;i++)
		{
			if(a[j]==b[i])
			{
				o=1;
			}
		}
		if(o==1)
		{
			while(true)
			{
			
				int s1=s.front();
				if(s1==b[i])
				{
					s.pop();
					
					break;
				}
				s.pop();
				d--;
			}
			s.push(b[i]);
			
		}
		else
		{
			s.push(b[i]);
			a[d]=b[i];
			d++;
		}
	}
	cout<<s.size();
	
	return 0;
}