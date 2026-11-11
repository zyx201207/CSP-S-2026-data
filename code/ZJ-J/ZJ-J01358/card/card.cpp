#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+20,M=3e5+10;
int n,m,a[N],ans[M];
queue<int> q;
int main()
{
	// 务必删除注释！！！
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		cout<<a[1]<<" "<<a[2];
		return 0;
	}
	else
	{
		for(int i=1;i<=m;i++)  
		{
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
