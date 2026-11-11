#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x,c,ans,a[200010],jiancha[6522];
int maxx=-1,cnt[6522];
queue<ll>q,qq,qr;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	jiancha[0]=1;
	for(int i=1;i<=31;i++) jiancha[i]=jiancha[i-1]*2;
	for(int i=1;i<=n;i++){
		x=a[i];
		for(int j=31;j>=0;j--){
			if(x>=jiancha[j]){
				x-=jiancha[j];
				cnt[j]++;
				if(cnt[j]>=m) maxx=max(maxx,j);
			}
		}
	}
	if(!maxx){
		cout<<1;
		return 0;
	}
	if(maxx==-1){
		cout<<0;
		return 0;
	}
	ans+=jiancha[maxx];
	for(int i=1;i<=n;i++){
		for(int j=31;j>=0;j--){
			if(a[i]>=jiancha[j]){
				a[i]-=jiancha[j];
				if(j==maxx) q.push(i);
			}
			if(j==maxx) break;
		}
	}
	for(int i=maxx-1;i>=0;i--){
		c=0;
		while(!q.empty()){
			ll now=q.front();
			q.pop();
			if(a[now]>=jiancha[i]){
				a[now]-=jiancha[i];
				c++;
				qr.push(now);
			}
			qq.push(now);
		}
		if(c>=m){
			ans+=jiancha[i];
			while(!qr.empty()){
				ll now=qr.front();
				qr.pop();
				q.push(now);
			}
		}
		else{
			while(!qq.empty()){
				ll now=qq.front();
				qq.pop();
				q.push(now);
			}
		}
		while(!qq.empty()) qq.pop();
		while(!qr.empty()) qr.pop();
	}
	cout<<ans;
	return 0;
}
