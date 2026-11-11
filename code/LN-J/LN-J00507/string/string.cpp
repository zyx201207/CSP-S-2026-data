#include<bits/stdc++.h>
#define int long long 
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
int n,a[200005],pos,p1,p2;
int s[200005];
char b[200005];
int c[200005][30];
void read(int &x)
{
	x=0;
	char c=gc();
	bool flg=0;
	while(c<'0' || c>'9')
	{
		if(c=='-') flg=1;
		c=gc();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=gc();
	}
	if(flg) x=-x;
}
int query(int l,int r,char ch)
{
	int ans=0;
	l=p1-(l-p2);r=p1-(r-p2);
	swap(l,r);
	int rs=lower_bound(s+1,s+1+pos,r)-s;
	int ls=lower_bound(s+1,s+1+pos,l)-s;
	
	cout<<l<<" "<<r<<"\n";
	cout<<"ls:"<<ls<<" "<<"rs:"<<rs<<" "<<s[1]<<"\n";
	if(ls==rs)
	{
		return ch==b[ls]?0:(r-l+1);
	}
	if(b[ls]==ch) ans+=s[ls]-l+1;
	if(b[rs]==ch) ans+=r-s[rs-1]; 
	if(ls+1!=rs) ans+=c[rs-1][ch-'a']-c[ls+1][ch-'a'];
	
	return r-l+1-ans;
}
void write(int x)
{
	if(x==LLONG_MIN)
	{
		cout<<LLONG_MIN;
		return;
	}
	if(x<0) x=-x,pc('-');
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
signed main()
{
	//freopen("string5.in","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);cin>>b[i];
	}
	for(int i=1;i<=n;i++) 
	{
		s[i]=s[i-1]+a[i];
		for(int j=0;j<25;j++)
		{
			if(b[i]==j+'a') c[i][j]=c[i-1][j]+a[i];
			else c[i][j]=c[i-1][j];
		}
	}
	if(s[n]&1) p1=p2=(s[n]+1)/2;
	else p1=s[n]/2,p2=s[n]/2+1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=p2)
		{
			pos=i;
			break;
		}
	}

	int ans=query(p2,s[pos],b[pos]);
	for(int i=pos+1;i<=n;i++)
	{
		write(ans);pc('\n');
		ans+=query(s[i-1]+1,s[i],b[i]);
	}
	write(ans);
	return 0;
}
