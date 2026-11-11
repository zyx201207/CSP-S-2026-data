#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct hw
{
	long long t;
	string c;	
};
hw a[N]; 
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{		
		cin>>a[i].t>>a[i].c;		
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l].t>a[r].t)
		{
			if(a[l].c!=a[r].c) sum+=a[r].t;
			a[l].t-=a[r].t;
			a[r].t=0;
			r--;
		}
		else
		{
			if(a[l].c!=a[r].c) sum+=a[l].t;
			a[r].t-=a[l].t;
			a[l].t=0;
			l++;
		}
	}
	cout<<sum;
	return 0;
}
