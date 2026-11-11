#include<bits/stdc++.h>//张哲 庆安初级中学 SN-J00787
using namespace std;
typedef long long l;
const int N=2e5+5;
l n,m,mx;
l a[N];
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				l x=a[i],y=a[j];
				l temp=x and y;
				cout<<mx<<' '<<temp<<' '<<a[i]<<' '<<a[j]<<endl;
				mx=max(temp,mx);
			}
		}
	}
	if(m==1) for(int i=0;i<n;i++) mx=max(a[i],mx);
	if(m==n)
	{
		mx=INT_MAX;
		for(int i=0;i<n;i++) mx=mx and a[i];
	}
	cout<<mx;
	return 0;
}
