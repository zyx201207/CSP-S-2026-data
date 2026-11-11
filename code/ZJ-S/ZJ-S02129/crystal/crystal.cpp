#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,a[10000001],f[10000001];
int s9(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		for(int j=1;j<=i;j++){
			if((f[i]-f[j-1]+m)>=a[i]*(i-j+1)){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
int s12(){
	int c[10000];
	for(int i=1;i<=n;i++){
		f[a[i]+100]++;
	}
	for(int i=0;i<=200;i++){
		int m1=m,cnt=f[i];
		for(int j=i-1;j>=0;j--){
			if((f[j]*(i-j))>m1){
				m1/=(i-j);
				ans=max(ans,cnt+m1);
				break;
			}
			m1-=f[j]*(i-j);
			cnt+=f[j];
		}
		if(m1>=0)ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
int s18(){
	int sum=abs(a[2]-a[1]);
	if(sum==0){
		cout<<n<<endl;
		return 0;
	}
	m/=sum;
	for(int i=1;i<=n;i++){
		if(m<i){
			cout<<i<<endl;
			return 0;
		}
		m-=i;
	}
	cout<<n<<endl;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mi=INT_MAX,ma=INT_MIN,p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])p=0;
		}
	}
	if(n<=5000)s9();
	else if(mi>=-100&&ma<=100)s12();
	else if(p==1)s18();
	return 0;
}
