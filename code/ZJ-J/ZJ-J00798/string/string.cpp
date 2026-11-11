#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,ans;
bool flag;
char ch;
string s;
struct node
{
	int o;
	char c;
}a[200005];
void ish()
{
	int l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r])  ans++;
		l++,r--;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].o>>a[i].c;
		cnt+=a[i].o;
		if(ch==0)  ch=a[i].c;
		if(ch!=a[i].c)  flag=1;
	}
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<min(a[1].o,a[0].o);
		return 0;
	}
	int ll=1,rr=n;
	while(a[ll].o==a[rr].o){
		if(a[ll].c!=a[rr].c)  ans+=a[ll].o;
		ll++,rr--;
	}
	for(int i=ll;i<=rr;i++)
		for(int j=1;j<=a[i].o;j++)
			s+=a[i].c;
	ish();
	cout<<ans;
	return 0;
}