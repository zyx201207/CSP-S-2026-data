#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
void solve1()//特殊性质A
{
	int t=1,ans=1;
	while(((m-t)>=0)&&(t<n))
	{
		m-=t;
		t++;
		ans++;
	}
	cout<<ans;
}
void solve2()//特殊性质B
{
	int k=a[2]-a[1],t=k,ans=1;
	while(((m-t)>=0)&&(t<n))
	{
		m-=t;
		t+=k;
		ans++;
	}
	cout<<ans;
}
void solve3()//暴力
{
	int ans=0;
	sort(a+1,a+n+1);
	priority_queue<int,vector<int>,greater<int> > f;
	for(int i=1;i<=n-1;i++)f.push(a[i+1]-a[i]);
	int t=1;
	while(m>=0||f.empty())
	{
		m-=f.top();
		f.pop();
		ans++;
	}
	cout<<ans;
}
bool check1()
{
	for(int i=1;i<=n;i++)if(a[i]!=i)return false;
	return true;
}
bool check2()
{
	int k=a[2]-a[1];
	for(int i=2;i<=n-1;i++)if((a[i+1]-a[i])!=k)return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check1())solve1();
	else if(check2())solve2();
	else solve3();
	return 0;
}
