#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,u,v;
long long a[2000005];
long long minn=INT_MAX;
map<long long,long long>mp;
void dfs1(long long now,long long cnt,long long pre){
	if(now==v){
		//cout<<cnt<<"\n";
		mp[cnt]++;
		minn=min(minn,cnt);
		return;
	}
	for(long long i=now+1;i<=n;i++){
		if(i!=now&&i!=pre){
			if(abs(a[i]-a[now])<=d)dfs1(i,cnt+1,now);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		long long ans=0;
		for(u=1;u<=n;u++){
			for(v=1;v<=n;v++){
				mp.clear();
				minn=INT_MAX;
				dfs1(u,0,-1);
				if(mp[minn]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
