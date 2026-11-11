#include<bits/stdc++.h>
using namespace std;

int n;
long long cnt;
struct node{
	int b;
	char c;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].b>>a[i].c;
	int l=1,r=n;
	while(l<r)
	{
		int m=min(a[l].b,a[r].b);
		if(a[l].c!=a[r].c)
		   cnt+=m; 
		a[l].b-=m;
		a[r].b-=m;
		if(a[l].b==0) l++;
		if(a[r].b==0) r--;
	}
	cout<<cnt;
	return 0;
} 
