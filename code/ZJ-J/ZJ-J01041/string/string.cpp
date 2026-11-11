#include<bits/stdc++.h>
using namespace std;
char a[100000000],b[100000000];
int k1,jj1,sum;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int w=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		if(w+x>100000000)
		{
			cout<<w;
			return 0;
		}
		for(int j=1;j<=x;j++)
		{
			a[w]=y;
			w++;
		}
	}
	for(int i=0;i<w;i++)
	{ 
		b[w-i-1]=a[i];
	}
	int cnt=0;
	for(int i=0;i<(w+1)/2;i++)
	{
		if(a[i]!=b[i]) cnt++;
	}
	cout<<cnt;
	return 0; 
}