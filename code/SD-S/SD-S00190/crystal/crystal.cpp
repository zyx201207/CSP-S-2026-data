#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll int
const int N=1e6+10;
int n,m;
int a[N],tm;
ll b[N];
bool check(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	int tm=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tm=min(tm,a[i]);
		if(abs(a[i])>100) f=0;
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0,t=1;
			for(int j=i-1;j>=1&&sum<=m;j--){
				sum+=a[i]-a[j];
				if(sum<=m) t++;
			}
			ans=max(ans,t);
		}
		cout<<ans;
	}else if(f){
		int ma=0;
		for(int i=1;i<=n;i++){
			b[a[i]+abs(tm)+1]++;
			ma=max(ma,a[i]+abs(tm)+1);
		}
		int ans=0;
		for(int i=1;i<=ma;i++){
			//cout<<b[i]<<" ";
			if(!b[i]) continue;
			int sum=m,t=b[i];
			for(int j=i-1;j>=0&&sum>0;j--){
				if(!b[j]) continue;
				int r=sum/(i-j);
				if(b[j]>=r){
					t+=r,sum-=(i-j)*r;
					break;
				}
				else t+=b[j],sum-=(i-j)*b[j];
			}
			ans=max(ans,t);
		}
		cout<<ans;
	}else if(check()){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(((n+a[1])*(n-a[1]+a[2]-a[1])/(a[2]-a[1]))/2<=m) ans=max(ans,i+1);
		}
		cout<<ans;
	}
	return 0;
}

