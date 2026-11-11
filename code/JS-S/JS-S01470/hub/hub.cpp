#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int re=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		re=(re<<3)+(re<<1)+c-'0';
		c=getchar();
	}
	return re*f;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,k;
void sol1()
{
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
	}
	if(k==n)
	{
		puts("0");
		return;
	}
	n=(n+1)/2+1;
	if(k>=n-2)
	{
		puts("1");
		return;
	}
	int ans=(n+3-k),lk=0;
	if(ans%4!=0)lk=1;
	write(ans/4+lk);
	putchar('\n');
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	//freopen("hub5.in","r",stdin);
	//freopen("tst.txt","w",stdout);
	
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c=read(),_=read();
	while(_--)
	{
		n=read();k=read();
		sol1();
	}
	return 0;
}
/*

dont press F11

seek if need long long

ensure function return

ensure file & extra output


n=(n+1)/2+1

n-1 seg

(ans-1)*2+ans*2+k-2>=n-1


4*ans>=n+3-k



*/
