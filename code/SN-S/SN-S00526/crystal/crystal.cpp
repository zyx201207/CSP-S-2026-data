#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

template<typename T1,typename T2>
inline void MIN(T1 &a,T2 b) {a=a<b?a:b;}
template<typename T1,typename T2>
inline void MAX(T1 &a,T2 b) {a=a<b?b:a;}

const int N=5e5+10;

int n;
ll a[N],m,s[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int l=1,ans=0;
	for (int r=1;r<=n;r++)
	{
		while ((r-l+1)*a[r]-(s[r]-s[l-1])>m) l++;
		MAX(ans,r-l+1);
	}
	
	cout<<ans;

	return 0;
}
