#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500006]={0};
long long h[500000]={0};
long long s[500006]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n>0)
	{
		for(int i=1;i<=n;i++)
		{
			memset(h,0,sizeof(h));
			for(int j=i;j<=n;j++)
			{
			
				if(h[a[j]]==0)
				{
					h[a[j]]=j;
					s[a[j]]++;
				}
				else
				{
				
					for(int k=h[a[j]];k<j;k++)
					{
						if(h[a[k]]>0)
						{
							h[a[k]]=0;
							s[a[k]]--;
						}
					
					}
					h[a[j]]=j;
					s[a[j]]++;
				
				}
			}
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout << s[i] << " ";
	}
	return 0;
}
