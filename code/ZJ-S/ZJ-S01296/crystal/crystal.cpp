#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx,x,sum,st;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		x+=sum*(a[i]-a[i-1]),sum++;
		for(int j=st;j<=i;j++){
		    if(x<=m) break;
		    x-=a[i]-a[j],st++,sum--;
		}
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
