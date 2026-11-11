#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],d,sum,ans,c[500005];
bool b;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=d) b=true;
	}
	if(b==false){
		if(d==0){
			cout<<n;
			return 0;
		}
		sum=(-1+sqrt(1+4*m/d))/2;
		m-=(d+sum*d)*sum;
		if(m>=(sum+1)*d) ans=2*sum+2;
		else ans=sum*2+1;
		if(ans>n) cout<<n;
		else cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int mm=m;
		sum=0;
		for(int j=1;j<=n;j++){
			if(a[i]<a[j]) c[j]=1e9;
			else c[j]=a[i]-a[j];
		}
		sort(c+1,c+n+1);
		for(int j=1;j<=n;j++){
			mm-=c[j];
			if(mm<0) break;
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}