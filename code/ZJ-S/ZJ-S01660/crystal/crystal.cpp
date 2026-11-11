#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],f[N];
long long v[N],cnt[N];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long num=i-1;
		long long ha=m-cnt[i-1];
		long long di=a[i]-v[i-1];
		long long us=num*di;
		//cout<<ans<<" "<<a[i]<<" "<<ha-us<<endl;
		if(us>ha){
			f[i]=ans;
			//cout<<"---------"<<endl;
			ans=2;
			cnt[i]=0;
			v[i]=a[i];
		}
		else{
			cnt[i]=cnt[i-1]+us;
			v[i]=a[i];
			ans++;
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}