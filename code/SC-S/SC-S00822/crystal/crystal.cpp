#include<bits/stdc++.h>
using namespace std;
long long n,d,a[500100],ans,b[500100],c[500100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long q=1;
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		while(c[i-1]+b[i]*(i-q)<c[i-1]||c[i-1]+b[i]*(i-q)>d){
			c[i-1]=c[i-1]-(a[i-1]-a[q]);
			q++;
		}
		c[i]=c[i-1]+b[i]*(i-q);
		ans=max(ans,i-q+1);
	}
	cout<<ans;
	return 0;
}