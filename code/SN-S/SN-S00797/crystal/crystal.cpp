#include<bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], c[500005], q[500005];

//75ptrs

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	cin>>n>>m;
	long long cha;
	for(int i = 1; i<=n; i++) 
	{
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	cha=a[2]-a[1];
	bool abf=1;
	for(int i = 1; i<n; i++)
	{
		c[i]=a[i+1]-a[i];
		if(c[i]!=cha) abf=0;
	}
	if(abf)
	{
		int cj=1, dj=0;
		while(dj<m && cj<n)
		{
			if(dj+c[cj]*cj<0) break;
			dj+=c[cj]*cj;
			cj++;
		}
		cout<<cj-1;
		return 0;
	}
	int cj=1, yd=n-1;
	memset(q, 0, sizeof(q));
	while(cj<n)
	{
//		memset(q, 0, sizeof(q));
		for(int i = 1; i<=n-cj; i++)
		{
			if(q[i]==-1) continue;
			if(q[i]+(cj)*c[i+cj-1] < 0)
			{
				q[i]=-1;
				yd--;
				continue;
			}
			q[i]=q[i]+(cj)*c[i+cj-1];
			if(q[i]>m) 
			{
//				cout<<q[i]<<'[';
				q[i]=-1;
				yd--;
			}
		}
//		for(int i = 1; i<=n-cj; i++) cout<<q[i]<<' ';
//		cout<<'|'<<yd<<endl; 
		if(yd<1) break;
		if(q[n-cj]!=-1) yd--;
		cj++;
//		cout<<'j'<<q[n-cj]<<'i';
		
	}
	cout<<cj;
	return 0;
}

