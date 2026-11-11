#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[10000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,j;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	b[a[i]]++;
	}
	int p,k,q=0;
	for(int i=1;i<=n;i++)
	{
		for( j=1;j<=n;j++)
		{
			if(a[i]==a[j]&&i!=j)
				q=1;
		}
		if(q==1){
			for(int z=j;z>=1;z--)
			{
				b[a[z]]++;
			}
		}	
	}
	for (int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
