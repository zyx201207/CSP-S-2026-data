#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,mind=-1e5;
	cin>>n>>m;
	int a[10001]={};
	int s[10001][10001]={};
	string x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i][i]=a[i]%2;
		a[i]/=2;
		for(int i=1;i<=n;i++)
		{
			swap(s[i][i],s[n-i][i]);
		}
		if(s[i][i]==1 && s[i][i+1]==1)
		{
			x[i]=1;
		}else
		{
			x[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int z=x[i]*pow(2,i);
			mind=max(mind,z);
		}
	}
	cout<<mind;
}
