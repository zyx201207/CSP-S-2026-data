#include<bits/stdc++.h>
using namespace std ;
int a[200020];
bool b[200020];
int n ;
int m ; 
int zdz = -1 ;
void dfs(int aa)
{
	if(aa>m)//生完了 
	{
		int t= 0 ;
		for(int i = 1 ; i <= n ; i++)
		{
			if(t==0&&b[i])
			t=a[i];
			if(b[i]&&t!=0)
			t=t&a[i];
		}
		//cout<<t<<endl;
		zdz=max(t,zdz);
		return ;
	}
	for(int i = 1 ; i <= n  ;i++)
	{
		if(!b[i])
		{
			b[i]=1 ;
			dfs(aa+1);
			b[i]=0;
		}
	}//生成 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int t = 0 ;//0_no  1_=1   2_ =B 3_=n
	if(m==1)
	t=1;
	if(m==n)
	t = 3 ;
	if(n>2000)
	t = 2 ;
	int maxx = -1 ;
	int all = 0 ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		if(t==1)
		maxx=max(maxx,a[i]);
		if(t==3)
		{
			if(all==0)
			all=a[i];
			else
			all=all&a[i];
		}
	} 
    if(t==1)
	cout<<maxx;
	else if(t==3)
	cout<<all;
	else if(t==2)
	cout<<(a[n]&a[n-1]);
	else
	{
		dfs(1);
		cout<<zdz;
		return 0 ;
	 }
	return 0 ;
 }
