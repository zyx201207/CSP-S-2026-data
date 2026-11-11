#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[210000];
char b[210000];
int n;
string s;
void check(long long e,long long r,int q,int w)
{
	if(b[q]!=b[w])
	{
		ans+=min(e,r);
	}
	if(e>r)
	{
		a[q]=a[q]-a[w];
		a[w]=0;
	}else if(e==r)
	{
		a[w]=0;
	}else{
		a[w]=a[w]-a[q];
		a[q]=0;
	}
	
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int q=1,w=n;
	for(int i=1;i<=1000000000000;i++)
	{
		if(w<=q)
		{
			cout<<ans;
			return 0;
		}
		check(a[q],a[w],q,w);
		if(a[q]==0)
		{
			q++;
		}
		if(a[w]==0)
		{
			w--;
		}
	}
	return 0;
}
