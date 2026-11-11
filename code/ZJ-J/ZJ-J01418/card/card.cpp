//草木逢春，慧如恒沙。神爱世人，妲门永存！！！ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
  
ll n,m,len;
const int maxM=3e5+10.27,maxN=5e5+10.27;
int pos[maxM],a[maxN];
int sta[maxN],cnt[maxM];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			pos[j]=0;
		}
		int posi=1;//初pos为1
		for(int j=i;j<=n;j++)
		{
			if(pos[a[j]])//存在a[j]
			{
				int p=posi;
				posi=pos[a[j]];
				for(int k=pos[a[j]];k<p;k++)
				{
					pos[sta[k]]=0;
					sta[k]=0;
				}
				pos[a[j]]=posi;
				sta[posi++]=a[j];
			}
			else
			{
				pos[a[j]]=posi;
				sta[posi++]=a[j];
			}
			//cout<<j<<':';for(int k=1;k<=m;k++){cout<<pos[k]<<" ";}cout<<endl;
		}
		for(int j=1;j<=m;j++)
		{
			if(pos[j])
			{
				cnt[j]++;
			}
			//cout<<pos[j]<<' ';
			//cout<<cnt[j]<<' ';
		}
		//cout<<endl;
		//for(int j=1;j<=m;j++){cout<<cnt[m]<<' ';}cout<<endl;
	}
	for(int j=1;j<=m;j++)
	{
		cout<<cnt[j]<<' ';
	}
	return 0;
}
