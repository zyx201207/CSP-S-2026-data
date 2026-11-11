#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],Max=0;
vector<int> jk;
void pt(vector<int>op)
{
	for(int i=0;i<op.size();i++)
	{
		cout<<a[op[i]]<<" ";
	}
	cout<<endl;
}
bool ch(long long z,vector<int>op)
{
	for(int i=0;i<op.size();i++)
	{
		if(op[i]==z)return true;
	}
	return false;
}
void dfs(long long now,long long z,vector<int>op)
{
	
	if(now==m)
}
		pt(op);
		if(z>Max)Max=z;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		vector<int>v=op;
		if(ch(i,op)==true)continue;
		v.push_back(i);
		dfs(now+1,z&a[i],v);
	}
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Max=max(a[i],Max);
	}
	if(m==1)
	{
	 	cout<<Max;
	 	return 0;
	} 
	for(int i=1;i<=n;i++)dfs(1,a[i],jk);
	cout<<Max;
	return 0;
}
