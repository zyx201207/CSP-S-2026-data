#include<iostream>
#include<algorithm>
#include<string.h>
#define int long long
using namespace std;
typedef long long ll;

const int N=5e5+5;
int n,ans;
ll num;
ll m,a[N],s[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) num++;
		else ans=max(ans,num),num=0;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		if((ll)a[i]*(i-now+1)-(s[i]-s[now-1])>m){
			ans=max(ans,i-now);
			while((ll)a[i]*(i-now+1)-(s[i]-s[now-1])>m) now++;
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}