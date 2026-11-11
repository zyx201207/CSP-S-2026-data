#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt,ans2;
long long a[5003];
int ans[5003][5003];
void dfs(int x,int y,int ste,int noww)
{
	if(ste>ans[x][y]&&ans[x][y]!=-1)return;
	if(ans[x-1][y]!=-1&&ste>ans[x-1][y]+1)return;
	if(ans[x][y-1]!=-1&&ste>ans[x][y-1]+1)return;
	if(noww==y)
	{
		if(ste==ans[x][y])cnt++;
		else
		{
			ans[x][y]=ste;
			cnt=1;
		}
		if(cnt>2)return ; 
		return;
	}
	for(int i=noww+1;i<=y;i++)
	{
		if(a[i]-a[noww]>d)break;
		dfs(x,y,ste+1,i);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--)
	{
		ans2=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			int g=(a[2]-a[1])/d;
			if(g==0)cout<<"0"<<endl;
			else cout<<(n-2*g+2)<<endl;
		}
		else {
				for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					ans[i][j]=-1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					cnt=0;
					dfs(i,j,0,i);
					if(cnt==0)break;
					if(cnt==2)ans2++;
				}
			}
			cout<<ans2<<endl;
		} 
	
	}
	return 0;
}
