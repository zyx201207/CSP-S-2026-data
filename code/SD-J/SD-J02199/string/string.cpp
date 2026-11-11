#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char c[200001]; 
int ps,pe,cs,ce,ns,ne;
long long sum;
void Qk1_1()
{
	if(cs!=ce)
		sum+=pe;
	ps-=pe;
	ne--;
	pe=a[ne];
}
void Qk1_2()
{
	if(cs!=ce)
		sum+=ps;
	ns++;
	ne--;
	ps=a[ns];
	pe=a[ne];
}
void Qk1_3()
{
	if(cs!=ce)
		sum+=ps;
	pe-=ps;
	ns++;
	ps=a[ns];
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	ps=a[1];
	cs=c[1];
	ns=1;
	pe=a[n];
	ce=c[n];
	ne=n;
	while(ns<ne)
	{
		if(ps>pe)
			Qk1_1();
		if(ps==pe)
			Qk1_2();
		if(ps<pe)
			Qk1_3();
	}
	cout<<sum;
	return 0;
}
