#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],n2;
int c[200010],ans;
int log2(int num)
{
	if(num==0)return -1;
	int result=0;
	int po=1;
	while(po<=num)
	{
		po*=2;
		result++;
	}
	return result-1;
}
void dfs(int pos,int ts)
{
	if(ts>n2)return ;
	if(pos>m)return ;
	c[pos]=ts;
	
	
	if(pos==m)
	{
		int atmp=2147483647;
		for(int i=1;i<=m;i++)
			atmp&=a[c[i]];
		ans=max(ans,atmp);
		return ;
	}
	int ytmp=2147483647;
	for(int i=1;i<=pos;i++)
	{
		ytmp&=a[c[i]];
		if(ytmp<=ans)return ;
	}
	for(int i=ts+1;i<=n2;i++)
	{
		dfs(pos+1,i);
	}
	return ;
}
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int pao=pow(2,log2(a[n]));
	while(1)
	{
		int shu=0;
		//Can Use Binary
		for(int i=n;i>=1;i--)
		{
			if(a[i]>=pao)shu++;
//			if(shu>=m)break;
		}
		if(shu<m)
			pao/=2;
		if(shu>=m)
		{
//			pao*=2;
			break;
		}
//		cout<<pao<<'\n';
	}
	queue<int> tmp;
	for(int i=1;i<=n;i++)
		if(a[i]>=pao)
		{
			tmp.push(a[i]);
//			cout<<a[i]<<' ';
		}	
	n2=tmp.size();
//	cout<<n2;
	for(int i=1;i<=n2;i++)
	{
		a[i]=tmp.front();
		tmp.pop();
//		cout<<a[i]<<' ';
	}
	sort(a+1,a+n2+1,cmp);
	for(int i=1;i<=n2;i++)
		dfs(1,i);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
