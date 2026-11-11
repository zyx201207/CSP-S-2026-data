#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int t[10005][10005];
int main() {
	freopen("subway,in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int ans=0;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	int k[n];
	for(int i=0;i<m;i++)
	{
		cin>>w[i]; 
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	int begin[q],end[q];
	for(int i=0;i<q;i++)
	{
		cin>>begin[i]>>end[i];
	}
	for(int i=0;i<q;i++)
	{
		int time=0;
		int b1,b2,c1,c2;
		int z1=0;
		for(int j=0;j<n;j++)
		{
			
			for(int o=0;o<k[j];o++)
			{
				if(a[j][o]==begin[i])
				{
					b1=j;
					time+=t[j][o];
					time+=w[begin[i]-1];
					c1=1;
				}
				if(a[j][o]==end[i])
				{
					b2=j;
					time+=t[j][o];
					time+=w[end[i]-1];
					c2=1;
				}
				if(c1==1&&c2==1)
				{
					z1=1;
					break;
				}
			}
			if(z1==1)
			{
				break;
			}
		}
		if(b1==b2)
		{
			ans=1; 
		} 
		int a1=0;
		while(ans==0)
		{
			int a2=0;
			while(true)
			{
				if(a[b1][a1]==a[b2][a2])
				{
					time+=t[b1][a1];
					time+=t[b2][a2];
					break;
				}
				if(a[b2][a2]==0)
				    break;
				a2++;
			}
			a1++;
			if(a[b1][a1]==0)
			break;
		}
		cout<<time<<endl;
	}
	return 0;
}
