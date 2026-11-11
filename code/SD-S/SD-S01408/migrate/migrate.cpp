#include<bits/stdc++.h>
#define ll long long
const ll N=2e6+100;
using namespace std;
ll C,T,n,D;
ll a[N],mi[N],f[N];
deque<ll>q,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&D);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ll ans=0;
		if(n>5010){
			printf("0\n");
			continue;
		}
		for(ll s=1;s<=n;s++){
			for(ll i=s;i<=n;i++)mi[i]=1e18,f[i]=0;
			mi[s]=0,f[s]=1;
			q.push_back(s);
			cnt.push_back(1);
			for(ll t=s+1;t<=n;t++){
				while(!q.empty()&&a[t]-a[q.front()]>D){
					cnt.front()-=f[q.front()];
					if(cnt.front()==0)cnt.pop_front();
					q.pop_front();
				}
				if(q.empty())break;
				mi[t]=mi[q.front()]+1;
				f[t]=cnt.front();
				while(!q.empty()&&mi[q.back()]>mi[t]){
					cnt.back()-=f[q.back()];
					if(cnt.back()==0)cnt.pop_back();
					q.pop_back();
				}
				if(!q.empty()&&mi[q.back()]==mi[t]){
					q.push_back(t);
					cnt.back()+=f[t];
				}
				else{
					q.push_back(t);
					cnt.push_back(f[t]);
				}
				if(f[t]==2)ans++;
			}
			while(!q.empty())q.pop_back();
			while(!cnt.empty())cnt.pop_back();
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
