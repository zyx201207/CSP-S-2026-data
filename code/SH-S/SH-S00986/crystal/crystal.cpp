#include<bits/stdc++.h>
using namespace std;


const long long N=500005;
long long f[N],a[N],dp[N];
bool flag=true;
bool cmp(unsigned long long u,unsigned long long v){
	return u<v;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m,mm;
	cin>>n>>m;
	mm=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=a[i-1]){
			flag=false;
		}
	}
	if(flag){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i]+a[i]-a[i-1];
			if(cnt>m){
				break;
			} 
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	unsigned long long _max=0,tal=0;
	for(unsigned long long i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			tal++;
		} else {
			tal=0;
		}
		_max=max(_max,tal);
	}
	cout<<tal<<endl;
	unsigned long long l=1,r=n,ans=0;
	while(l<r){
		m=mm;
		unsigned long long cnt=0;
		bool flag=true;
		unsigned long long mid=(l+r)>>1;
		for(unsigned long long i=mid;i>=1;i--){
			if(m>=a[mid]-a[i]){
				m-=a[mid]-a[i];
				cnt++;
			} else {
				flag=false;
				break;
			}
		}
		if(flag){
			l=mid+1; 
		} else {
			r=mid-1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
} 
//jue wang , 
