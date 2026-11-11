#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt,ans;
int a[N][40],x[N];
bool mark[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		int k=1,y=x[i];
		while(y!=0)
		{
			a[i][k]=y%2;
			y/=2;
			k++;
		}
		cnt=max(cnt,k-1);
	}
	for(int i=cnt;i>=1;i--)
	{
		int k=0;
		for(int j=1;j<=n;j++)
			if(a[j][i]==1 && mark[j]==false) k++;
		if(k>m && i!=1){
			for(int j=1;j<=n;j++)
				if(a[j][i]==0) mark[j]=true;
		}
		else if(k==m){
			for(int j=1;j<=n;j++)
				if(a[j][i]==1 && mark[j]==false){
					if(ans==0) ans=x[j];
					else ans=ans&x[j];
				}
			break;
		}
		else if(i==1){
			for(int j=1;j<=n;j++)
				if(mark[j]==false){
					if(ans==0) ans=x[j];
					else ans=ans&x[j];
				}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
