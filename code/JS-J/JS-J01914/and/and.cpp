#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200001];
int res[200001];
int tmp[200001];
int lenres=0,lentmp=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		res[++lenres]=a[i];
	}
	int ans=0;
	for(int i=29;i>=0;i--)
	{
		lentmp=0;
		for(int j=1;j<=lenres;j++)
		{
			if(res[j]>>i&1)
			{
				tmp[++lentmp]=res[j];
			}
		}
		if(lentmp>=m)
		{
			ans+=(1<<i);
			lenres=0;
			for(int j=1;j<=lentmp;j++)
			{
				res[++lenres]=tmp[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
