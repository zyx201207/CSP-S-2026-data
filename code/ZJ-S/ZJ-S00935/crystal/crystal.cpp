#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],ans,p,b[N],l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	l=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(b[i]-b[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
}
