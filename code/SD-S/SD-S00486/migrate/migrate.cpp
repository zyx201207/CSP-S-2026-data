#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[510000];
long long minn=0x3f3f3f3f,cnt,sum;
map<long long,long long>mp;
void dfss(long long x,long long v,long long ans){
	if(x==v){
		if(minn>ans){
			minn=ans;
		}
		return ;
	}
	for(long long i=x+1;i<=x+d&&i<=v;i++){
		if(mp[i]){
			dfss(i,v,ans+1);
		}
	}
}
void dfs(long long x,long long v,long long ans){
	if(x==v){
		if(ans==minn){
			cnt++;
		}
		return ;
	}
	for(long long i=x+1;i<=x+d&&i<=v;i++){
		if(mp[i]){
			dfs(i,v,ans+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			mp[x[i]]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i!=j){
					dfss(x[i],x[j],0);
					//cout<<i<<" "<<j<<":"<<minn<<"\n";
					dfs(x[i],x[j],0);
					if(cnt==2){
						sum++;
					} 
					//cout<<cnt<<" "<<sum<<"\n";
					cnt=0;
					minn=0x3f3f3f3f;
				}
			}
		}
		printf("%lld\n",sum);
		sum=0;
		for(int i=1;i<=n;i++){
			mp[x[i]]=0;
		}
	}
	
	return 0;
}
