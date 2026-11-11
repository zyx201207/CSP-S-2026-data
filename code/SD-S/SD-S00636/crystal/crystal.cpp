#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int n,m,a[M],p=1,cst,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cst+=(a[i]-a[i-1])*(i-p);
		while(cst>m){
			cst-=a[i]-a[p];
			p++;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<"\n";
}
