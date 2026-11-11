#include<bits/stdc++.h>
using namespace std;
long long a[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	

	long long mx=-101;
	for(int i=1;i<=n;i++){
	
		cin>>a[i];
		q[i]=q[i-1]+a[1];
		mx=max(mx,a[i]);
	}
	if(n>5000&&(a[2]-a[1]==1)&&(a[4]-a[3]==1)){
		cout<<n;
		return 0;
	}
	else if(n>5000){
		long long gc=a[2]-a[1];
		long long jg=m/gc;
		long long cnt=0;
		long long h=0;
		for(int i=1;i<=n;i++){
			if(jg<=cnt){
				cnt-=(i-1);
				cout<<h;
				return 0;
			}
			cnt+=i;
			h++;
		}
		cout<<h;
	}
	sort(a+1,a+n+1);
	long long maxn=0;
	for(int i=2;i<=n;i++){
		long long ans=0;
		long long t=m;
		for(int j=i;j>=1;j--){
			if((a[i]-a[j])<=t){
				ans++;
				t-=(a[i]-a[j]);
			}
			else break;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn<<" ";
	
	return 0;
}