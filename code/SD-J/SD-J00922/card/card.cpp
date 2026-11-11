#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],c[300005],s[300005];
bool e[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int k=1;k<=n;k++)
	{
		int cnt=0;
		memset(e,0,sizeof(0));
		memset(s,0,sizeof(0));
		for(int i=k;i<=n;i++)
		{
			if(e[a[i]])
			{
				int cc=cnt;
				for(int j=cc;j>=1;j--)
					if(s[j]==a[i])
					 	break;
					else
					{
						e[s[j]]=0;
						s[j]=0;
						cnt--;
					}
			}
			else
			{
				cnt++;
				s[cnt]=a[i];
				e[a[i]]=1;
			}	
		}
		for(int i=1;i<=cnt;i++)
		{
			c[s[i]]++;
		}		
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
