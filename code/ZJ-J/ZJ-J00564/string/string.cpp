/*
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;
int n;
char c[N];
ll pre[N],fut[N],a[N],ans;

int main()
{
//	freopen("string4.in","r",stdin);
//	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i]>>c[i];
	pre[0] = 0;
	fut[n+1] = 0;
	for(int i = 1;i<=n;i++) pre[i] = pre[i-1]+a[i];//Ç°×º 
	for(int i = n;i>=1;i--) fut[i] = fut[i+1]+a[i];//ºó×º 
	for(int i = 1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	for(int i = 1;i<=n;i++) cout<<c[i]<<" ";
	cout<<endl;
	for(int i = 1;i<=n;i++) cout<<pre[i]<<" ";
	cout<<endl;
	for(int i = 1;i<=n;i++) cout<<fut[i]<<" ";
	cout<<endl;
	int l = 1,r = n;//Ë«Ö¸Õë
	while(l<r)
	{
		bool b = 0;
		while(fut[r]<=pre[l]&&l<r)
		{
			b = 1;
			if(c[r] != c[l]) ans+=a[r];
			cout<<"r: "<<l<<" "<<r<<" "<<ans<<"\n";
			r--;
		}
		if(b)
		{
			if(c[l] != c[r]) ans+=pre[l]-fut[r+1];
			l++;
			cout<<ans<<endl;
		}
		b = 0;
		while(pre[l]<=fut[r]&&l<r) 
		{
			b = 1;
			if(c[l] != c[r]) ans+=a[l];
			cout<<"l: "<<l<<" "<<r<<" "<<ans<<"\n";
			l++;
		}
		if(b)
		{
			if(c[l] != c[r]) ans+=fut[r]-pre[l-1];
			r--;
			cout<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
*/
/*
5
1 a
3 b
2 a
1 b
3 a
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 1e8+10;
const int N = 2e5+10;
int a[N];
char c[N];
char s[M];
int n;
ll tot = 0;
int ans = 0;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=a[i];j++)
		{
			s[++tot] = c[i];
		}
	}
	for(int i = 1;i<=tot/2;i++)
	{
		if(s[i] != s[tot+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
