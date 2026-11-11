#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[300005],n,m,end1,x[300005],as[300005];
string a[500005],b[500005];
int print(string as){
	int ans=0;
	for(int i=0;i<as.size();i++)
	{
		ans*=10;
		ans+=as[i]-'0';
	}
	return ans;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			memset(as,0,sizeof as);
			memset(x,0,sizeof x);
			end1=0;
			for(int j=1;j<=n;j++)
			{
				b[j]="";
			}
			for(int j=i;j<=n;j++)
			{
				end1++;
				b[end1]=a[j];
				if(as[print(a[j])]==1)
				{
					for(int k=x[print(a[j])]+1;k<end1;k++)
					{
						as[print(a[k])]--;
					}
					end1=x[print(a[j])];
				}
				else
				{
					x[print(a[j])]=end1;
					as[print(a[j])]++;
				}
			}
			for(int j=1;j<=end1;j++)
			{
				d[print(b[j])]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<d[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
	}
	return 0;
}
