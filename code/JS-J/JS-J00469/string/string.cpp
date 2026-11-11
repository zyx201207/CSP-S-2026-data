#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
struct node{
	int x;
	char ch;
}a[200005];
//Time that you hold deep inside your eyes
//Stories unfold from the path behind
//This life's a dream,I'll trace our years
//To leave our names,for all to hear
//When feathers fail,let our wings be twined
//We're meant for the sky that're unconfined
//When wind drops the burden wings sustain
//Yet time still I'll see you again
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read(),ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i].x=read();
		cin>>a[i].ch;
	}
	int l=1,r=n;
	while(l<r)
	{
		int tmp=min(a[l].x,a[r].x);
		if(a[l].ch!=a[r].ch)ans+=tmp;
		a[l].x-=tmp;a[r].x-=tmp;
		if(a[l].x==0)l++;
		if(a[r].x==0)r--;
	}
	cout<<ans;
	return 0;
}
