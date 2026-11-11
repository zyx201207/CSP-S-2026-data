#include<bits/stdc++.h>
using namespace std;
int a[30010],b[30010],c[30010],d[50020];
int m,n,cnt=0; 
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	for(int j=cnt+1;j<=n;j++)
    	{
    		b[a[j]]++;
    		if(b[a[j]]>1){
    			for(int z=c[a[j]];z<=j-cnt;z++)if(b[a[z]]>0)b[a[z]]--;
    			b[a[j]]++;
			}
			c[a[j]]=j-cnt;
		}
		for(int j=1;j<=m;j++)
    	{
    		if(b[a[j]]>0)d[j]++;
    		b[a[j]]=0;
    		c[a[j]]=0;
		}
    	cnt++;
	}
	for(int j=1;j<=m;j++)cout<<d[j]<<" ";
    return 0;
}
