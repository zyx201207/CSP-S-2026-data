#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],op[N],ans=1,ob,s[N];
bool IA=true,IB=true,f=false;
void solve_A()
{
	for(int i=2;i<=n;i++)
	{
		if((m-i+1)>=0) ans++;
		m=m-i+1;
	}
	cout<<ans;
	return;
}
void solve_B()
{
	for(int i=2;i<=n;i++)
	{
		int r=(ob*(i-1));
		if((m-r)>=0) ans++;  
		m=m-r;
	}
	cout<<ans;
	return;
}
void dfs(int x,int h,int res)
{
	if(h-s[x]>=0)
	{
		//cout<<"nex"<<endl;
		dfs(x+1,h-s[x],++res);
	}
	if(f) return;
	cout<<res<<' ';
	f=true;
	return;
}
void solve_small()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) op[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++) s[i]=op[i]+op[i-1];
//	for(int i=1;i<=n;i++) cout<<s[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<op[i]<<' ';
//	cout<<endl;
	dfs(2,m,1);
	return;
}
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  	scanf("%d",&a[i]);
  	op[i]=a[i]-a[i-1];
  	if(i!=1&&i!=2&&op[i]!=op[i-1])
  	{
  		IA=false;
  		IB=false;
	}
	if(i!=1&&i!=2&&(op[i]!=1||op[i-1]!=1)) IA=false;
  }
  if(n==1)
  {
  	cout<<1;
  	return 0;
  }
  //cout<<IA<<' '<<IB<<endl;
  if(IA)
  {
  	solve_A();
  	return 0;
  }
  if(IB)
  {
  	ob=op[2];
  	//cout<<ob<<endl;
  	solve_B();
  	return 0;
  }
  solve_small();
  return 0;
}
