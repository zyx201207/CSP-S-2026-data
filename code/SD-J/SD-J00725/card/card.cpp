#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool ppp=true;
	string s="";
	map<int,int> sl;
 	map<int,int> mp;
 	map<int,int> pp;
 	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			ppp=false;
		}
		if(pp[a[i]]==0)
		{
			b[++cnt]=a[i];
		}
		pp[a[i]]++;
	}
	if(ppp){
		int ywy=m;
		for(int i=ywy;i>=1;i--)
		{
			cout<<m-i<<' ';
		}
		return 0;
	}
	int ans=0;
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		{
			x++;
			if(mp[a[j]]!=0)
			{
				for(int k=mp[j];k<x;k++)
				{
					mp[a[k]]=0;
				}			
			}
			mp[a[j]]=x;
			
		}
		for(int o=1;o<=i*n;o++)
		{
			if(mp[a[o]]!=0)
			{
				sl[a[o]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<sl[b[i]];
		if(i!=cnt) cout<<" ";
	}
return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
//4 3 
//1 2 1 3
