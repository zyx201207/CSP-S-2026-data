#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
void optimize()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
int n,m,a[N],f[N],ans;
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	optimize();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int j=0;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		while(f[i]-f[j]-j*(a[i]-a[j])>m) 
			j++;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
