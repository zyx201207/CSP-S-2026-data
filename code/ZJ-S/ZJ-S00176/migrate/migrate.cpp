#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,t;
ll a[N];
ll minn,nsum,ans;
int n;
ll d;
void dfs(int cur,ll num,ll en){
	if(cur==en){
		if(num==minn){
			nsum++;
		}else if(num<minn){
			nsum=1;
			minn=num;
		}
		return;
	}
	for(int i=cur+1;i<=en;i++){
		if(a[i]-a[cur]>d) break;
		dfs(i,num+1,en);
	}
}
void c1112(){
	int n;
	ll d,gc;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		gc=a[2]-a[1];
		ll num=d/gc;
		if(num<=1){
			cout<<"0\n";
			continue;
		}
		num*=2;
		cout<<max(0ll,n-num+1)<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		c1112();
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				minn=LLONG_MAX;
				nsum=0;
				dfs(i,0,j);
				if(nsum==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
