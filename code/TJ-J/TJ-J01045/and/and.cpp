#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int n,m,ans;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	sc("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		sc("%d",&a[i]);
	}
	sort(a,a+n);
	ans=a[n-m];
	for(int i=1;i<=m;i++){
		ans=ans&a[i+n-m-1];
	}
	pf("%d",ans); 
	return 0;
} 
