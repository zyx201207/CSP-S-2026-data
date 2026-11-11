#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+8;
int n;
char chs[2][MAXN];
long long sz[2][MAXN],len;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sz[0][i]>>chs[0][i],len+=sz[0][i];
	for(int i=1;i<=n;i++) sz[1][i]=sz[0][n-i+1],chs[1][i]=chs[0][n-i+1];
	long long ans=0,pos0=1,pos1=1,i=1,j=1;
	while(pos0<=len/2&&pos1<=len/2)
	{
		if(chs[0][i]!=chs[1][j])
		{
			if(pos0+sz[0][i]>pos1+sz[1][j])
			{
				while((pos0+sz[0][i]>pos1+sz[1][j])&&chs[0][i]!=chs[1][j]&&pos0<=len/2&&pos1<=len/2) pos1+=sz[1][j],j++;
				ans+=pos1-pos0;
			}
			else
			{
				while((pos0+sz[0][i]<=pos1+sz[1][j])&&chs[0][i]!=chs[1][j]&&pos0<=len/2&&pos1<=len/2) pos0+=sz[0][i],i++;
				ans+=pos0-pos1;
			}
		}
		else
		{
			if(pos0+sz[0][i]>pos1+sz[1][j])
			{
				while((pos0+sz[0][i]>pos1+sz[1][j])&&chs[0][i]==chs[1][j]&&pos0<=len/2&&pos1<=len/2) pos1+=sz[1][j],j++;
				if(pos1+sz[1][j]<len/2) ans-=(pos1-pos0);
			}
			else
			{
				while((pos0+sz[0][i]<=pos1+sz[1][j])&&chs[0][i]==chs[1][j]&&pos0<=len/2&&pos1<=len/2) pos0+=sz[0][i],i++;
				if(pos0+sz[0][i]<len/2) ans-=(pos0-pos1);
			}
		}
	}
	cout<<ans;
	return 0;
}
