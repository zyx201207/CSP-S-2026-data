#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
long long n,m,ans,A[600000],B[600000];
//struct node{
//	long long a,b;
//	bool operator <(const node & x)const{
//		if(a==x.a) return b>x.b;
//		else return a>x.a;
//	}
//};
//set<int>::iterator it;
//priority_queue <long long,vector<long long>,greater<long long> > Q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long q=0,w=0,e=2,r,i,j,x=0,y=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		B[i]=A[i]-A[i-1];
	}
	for(i=2;i<=n;i++)
	{
		y++;
		x+=B[i]*y;
		w+=B[i];
		while(x>m)
		{
			ans=max(ans,y);
			x-=w;
			w-=B[e];
			y--;
			e++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//<<fixed<<setprecision()Oct31==Dec25?
