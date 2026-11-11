#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n+1-i;j++)
		{
			string s;
			if(!vis[arr[j]]){
				vis[arr[j]]=1;
				s=s+to_string(arr[j]);
			}
			else{
				for(int k=1;k<=n;k++)
				{
					if(arr[k]==arr[j])
					{
						for(int m=k;m<=n;m++)
						{
							arr[m]=-1;
						}
						arr[]
						break;
					}
				}
				arr[]
			}
			arr[]
		}
	}
	return 0;
}
