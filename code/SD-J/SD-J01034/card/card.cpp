#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],num[300010],xb,st[500010],ans[300010],k,bj[300010],zbj;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;++i)
{
	cin>>a[i];if(a[i]<a[i-1])zbj=1;
}
if(zbj==1)
{
	for(int q=1;q<=n;++q)
{xb=1;
	for(int i=q;i<=n;++i)
	{k=a[i];
		if(num[k]!=0)//如果出现了 
		{
			xb=num[k]+1;//删除 
		}
		else {//如果没出现过 
			st[xb++]=k;//加入栈内 
			num[k]=xb-1;//更新出现的位置 
		}
	}
	for(int i=1;i<=m;++i)num[i]=0;
	for(int i=1;i<xb;++i)
	{
		if(bj[st[i]]==0)
		{
			ans[st[i]]++;bj[st[i]]=1;
		}	
		cout<<st[i]<<" ";
	}cout<<endl;
	for(int i=1;i<xb;++i)
	{
		bj[st[i]]=0;
	}
}

for(int i=1;i<=m;++i)
{
	cout<<ans[i]<<" ";
}
}
else {
	for(int i=n;i>=1;--i)
	{
		if(a[i]!=a[i+1])
		{
			ans[a[i]]=i;
		}
	}
}for(int i=1;i<=m;++i)
{
	cout<<ans[i]<<" ";
}
return 0;
}

