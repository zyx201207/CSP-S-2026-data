#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAX=5E5+10;
long long a[MAX],ans,pre[MAX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	long long l=1,r=1;
	while(r<=n){
		if((r-l+1)*a[r]-pre[r]+pre[l-1]<=m){
			ans=max(r-l+1,ans);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
