#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int in,ci,all;
	cin >> in >> ci;
	int eng[in];
	int jl[in];
	for(int i=0;i<in;i++)
	{
		cin >> eng[i];
		all+=eng[i];
	}
	all/=in;
	for(int i=0;i<in;i++)
	{
		if(eng[i]-all<=0)
		{
			jl[i]=all-eng[i];
		}
		else
		{
			jl[i]=eng[i]-all;
		}
	}
	all=0;
	for(int i=0;i<in;i++)
	{
		for(int j=0;j<in-1;j++)
		{
			int a;
			if(jl[j]>jl[j+1])
			{
				a=jl[j];
				jl[j]=jl[j+1];
				jl[j+1]=a;
			}
		}
	}
	for(int i=0;i<in;i++)
	{
		all+=jl[i];
		if(all>=ci)
		{
			cout << i+1 <<endl;
			break;
		}
	}
 
	return 0;
}