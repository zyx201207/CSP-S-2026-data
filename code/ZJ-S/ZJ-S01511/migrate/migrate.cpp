#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n;
long long d;
long long x[N];
int minn[N],cnt[N];
int f(int s){
	minn[s]=0;
	cnt[s]=1;
	int res=0;
	int l;
	for(int i=s+1;i<=n;i++){
		minn[i]=1e9;
		if(x[s]>=x[i]-d)l=s;
		else l=lower_bound(x+s,x+i+1,x[i]-d)-x;
		for(;l<i;l++){
			if(minn[l]==minn[i]-1)cnt[i]+=cnt[l];
			else if(minn[l]<minn[i]-1){
				minn[i]=minn[l]+1;
				cnt[i]=cnt[l];
			}
		}
		if(cnt[i]==2)res++;
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n>=5000){
			long long res=n;
			res*=(n-1);
			res/=2;
			int l;
			for(int i=1;i<=n;i++){
				if(x[1]>=x[i]-d)l=1;
				else l=lower_bound(x+1,x+n+1,x[i]-d)-x;
				res-=i-l;
			}
			cout<<res<<'\n';
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)ans+=f(i);
		cout<<ans<<'\n';
	}
	return 0;
}
