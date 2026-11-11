#include <iostream>
using namespace std;
int a[500005],b[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//暴力
	//看我超级模拟
	//草，不会memset 
	//for吧 
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	    int ans=0;
		for(int k=i;k<=n;k++)
		{
			bool p=0;
		    for(int j=1;j<=ans;j++)
		    {
		    	if(a[k]==b[j]) p=1;
		    	if(p==1) {b[j]=0;ans--;}
	        }
	        ans++;
	        b[ans]=a[k];
	    }
	    for(int o=1;o<=ans;o++)
	    {
	    	c[b[o]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	//12pts+25pts+40pts+100pts=177pts>省二，也够 
	//不太贪心了 
	return 0;
}
//米哈游是CCR的父亲 
