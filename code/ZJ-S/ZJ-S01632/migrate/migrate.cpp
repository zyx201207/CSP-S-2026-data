#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int tp,T,n,pre[2000005],nxt[2000005],cnxt[2000005],cpre[2000005];ll w[2000005],d,ans,spre[2000005],snxt[2000005];
void solve(){
	cin>>n>>d;for(int i=1;i<=n;i++)cin>>w[i],pre[i]=nxt[i]=cnxt[i]=cpre[i]=spre[i]=snxt[i]=0;ans=0;
	for(int i=n-1,p=n;i>=1;i--){
		while(w[p]-w[i]>d)p--;
		if(p>i)nxt[i]=p,cnxt[p]++;
	}
	for(int i=2,p=1;i<=n;i++){
		while(w[i]-w[p]>d)p++;
		if(p<i)pre[i]=p,cpre[p]++;
	}
	for(int i=1;i<=n;i++){
		spre[i]=cnxt[i];
		if(nxt[pre[i]]==i)spre[i]+=spre[pre[i]];
	}
	for(int i=n;i>=1;i--){
		snxt[i]=cpre[i];
		if(pre[nxt[i]]==i)snxt[i]+=snxt[nxt[i]];
	}
	for(int i=2;i+1<n;i++){
		ll now1=0,now2=0,now3=0,now4=0;
		if(pre[i+1]&&nxt[i]&&pre[i+1]<i&&nxt[i]>i+1){
			ans+=1ll*cnxt[i+1]*cpre[i];
			now1+=1ll*cnxt[i+1]*cpre[i];
		}
		if(pre[i]&&pre[i]==pre[i+1]&&nxt[i]&&nxt[i]==nxt[i+1]&&nxt[pre[i+1]]==i+1&&pre[nxt[i]]==i){
			ans+=1ll*spre[pre[i]]*snxt[nxt[i]];
			now2+=1ll*spre[pre[i]]*snxt[nxt[i]];
		}
		if(nxt[i]&&nxt[i]==nxt[i+1]&&pre[nxt[i]]==i){
			ans+=1ll*cnxt[i+1]*snxt[nxt[i]];
			now3+=1ll*cnxt[i+1]*snxt[nxt[i]];
		}
		if(pre[i]&&pre[i]==pre[i+1]&&nxt[pre[i+1]]==i+1){
			ans+=1ll*spre[pre[i]]*cpre[i];
			now4+=1ll*spre[pre[i]]*cpre[i];
		}
		//cout<<" "<<i<<" "<<i+1<<" "<<now1<<" "<<now2<<" "<<now3<<" "<<now4<<'\n';
	}
	//for(int i=1;i<=n;i++){
	//	cout<<i<<" "<<pre[i]<<" "<<nxt[i]<<" "<<cpre[i]<<" "<<cnxt[i]<<" "<<spre[i]<<" "<<snxt[i]<<'\n';
	//}
	cout<<ans<<'\n';
}
signed main(){
	//system("fc migrate6.ans migrate.out");exit(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>tp>>T;while(T--)solve();
}