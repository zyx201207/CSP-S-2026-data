#include<bits/stdc++.h>
using namespace std;
long long n,m,s,u,q,ans,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		s=1,u=m,q=i;
		while(u>0 && q>0){
			s++,u=u-(a[i]-a[--q]);
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}