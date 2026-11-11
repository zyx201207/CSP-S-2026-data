#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
long long n,d,ans,A[7000000],B[7000000];
//bool Bi[7000000];
vector <long long> V[7000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long q,w,e,r,i,j,x,y,c,t;
	cin>>c>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>A[i];
			B[i]=A[i]-A[i-1];
		}
		q=A[2]-A[1];
		w=d/q;
		if(w<=1)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			e=n-2*w+1;
			if(e<0) e=0;
			cout<<e<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

