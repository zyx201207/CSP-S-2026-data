#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[500005],b[500005],c,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	c=0;
	d=0;
	for(int i=1;i<=n;i++)b[i]=a[n]-a[i];
	long long k=0;
	for(int j=n;j>=1;j--){
		if(k+b[j]>m){
			d=n-j+1;
			ans=max(ans,d);
			k=k+b[j];
			c=c+a[n]-a[n-1];
			k=k-(n-j)*c;
			n--;
		}
		else{
			k=k+b[j]-c;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
