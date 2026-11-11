#include<bits/stdc++.h>
using namespace std;
long long n,m,l,o;
long long a[500010];
long long ans,cox,pop;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n+1;i++){
		cin>>a[i];
	}
	sort(a+2,a+n+2);
	for(int i=2;i<=n+1;i++){
		cox=pop+1;
		l=m;
		long long u=pop*(a[i]-a[i-1])+o;
		while(l<u){
			cox-=1;
			u=u-(a[i]-a[i-pop]);
			pop--;
		}
		ans=max(ans,cox);
		pop=cox;
		o=u;
	}
	cout<<ans;
	return 0; 
}
