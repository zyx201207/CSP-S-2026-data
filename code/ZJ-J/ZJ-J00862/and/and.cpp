#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll k,a[N];
int n,m;
ll ans;
int cnt[5];
void dfs(int pos,int cnt,ll cost,bool f){
	if(pos>n){
		if(cnt==m) ans=max(ans,cost);
		return ;
	}
	dfs(pos+1,cnt,cost,f);
	if(!f) dfs(pos+1,cnt+1,a[pos],!f);
	else dfs(pos+1,cnt+1,cost&a[pos],f);
}
bool f;
bool ff;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) k=a[i];
		else k&=a[i];
	}
	if(m==n){
		cout<<k;
		return 0;
	
	}
	else if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	else if(m==1){
		ll mx=-1;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}else if(n<=10000 && m==2){
		ll ans2=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans2=max(ans2,a[i]&a[j]);
		}
		cout<<ans2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool f2=0;
		for(int j=0;j<=30;j++){
			if(a[i]==(1<<j)-1){
				f2=1;
				break;
			}
		}
		if(!f2){
			f=1;
			break;
		}
	}
	if(!f){
		sort(a+1,a+n+1,greater<ll>());
		ll ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			ff=1;
			break;
		}
	}
	if(!ff){
		sort(a+1,a+n+1,greater<ll>());
		ll ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,greater<ll>());
	ll ansa=a[1];
	for(int i=2;i<=m;i++) ansa&=a[i];
	cout<<ansa;
	return 0;
}
/*
5 3 
3 2 1 1 0
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
