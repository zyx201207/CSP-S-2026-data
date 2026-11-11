#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool is[200005];
int ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++) if((a[j]>>i)%2==1&&is[j]==false) sum++;
		if(sum<m) continue;ans+=1<<i;
		for(int j=1;j<=n;j++) if((a[j]>>i)%2==0&&is[j]==false) is[j]=true; 
	} 
	cout<<ans;
	return 0;
}/*

*/ 
