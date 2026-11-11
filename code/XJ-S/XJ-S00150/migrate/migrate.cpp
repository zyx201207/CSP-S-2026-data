#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll a[N];
ll c,T,n,d;
ll cd[N],cnt=0;
ll minstp;
void dfs(ll fir,ll lst,ll now,ll stp){
	if(now==lst){
		cd[++cnt]=stp;
		minstp=min(minstp,stp);
		//cout<<fir<<' '<<lst<<' '<<now<<' '<<stp+1<<endl;
		return;
	}
	for(int i=now+1;i<=lst;i++){
		if(a[i]-a[now]<=d){
			dfs(fir,lst,i,stp+1);
		}
	}
	return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&T); 
    while(T--){
		scanf("%lld %lld",&n,&d); 
		ll ans;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]); 
		}
		if(c==1 || c==2 || (c!=11 && c!=12)){
			//sub 1,2
			ans=0;
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					cnt=0,minstp=1e18;
					ll cnt_minstp=0;
					dfs(i,j,i,0);
					//cout<<i<<' '<<j<<endl;
					for(int k=1;k<=cnt;k++){
						//cout<<cd[k]<<endl;
						if(cd[k]==minstp){
							cnt_minstp++;
						}
					}
					if(cnt_minstp==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		if(c==11 || c==12){
			//sub 11,12
			ll D=a[2]-a[1];
			ll x=d/D;
			if(x==1 || x==0){
				ans=0*1LL;
			}else{
				ll L=2*x-1;
				ans=max(n-L,0*1LL);
			}
			printf("%lld\n",ans);
		}
	}
	//ccf妈妈对这个T3太严厉了，拼尽全力写出来小数据和特判A，能拿16pts估计 
    return 0;
}
