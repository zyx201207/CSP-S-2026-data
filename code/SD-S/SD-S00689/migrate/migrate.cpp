#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N],n,d;
bool check(int u,int v){
	for(int i=u;i<v;i++){
		if(abs(a[i+1]-a[i])>d) return false;
	}
	return true;
}
bool f(int u,int v,int x){
	int cnt1=0,cnt2=0;
	for(int i=u+1;i<=v;){
		cnt1++;
		int j=i+1;
		while(j<=v&&abs(a[j]-a[i])<=d){
			j++;
		}
		i=j;
	}
	if(cnt1+1!=x) return false;
	for(int i=u+2;i<=v;){
		cnt2++;
		int j=i+1;
		while(j<=v&&abs(a[j]-a[i])<=d){
			j++;
		}
		i=j;
	}
	if(cnt2+1!=x) return false;
	return true;
}
void solve(){
	cin>>n>>d;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int u=1;u<=n-3;u++){
		for(int v=u+3;v<=n;v++){
			int x=abs((a[v]-a[u]))/d+(abs(a[v]-a[u])%d!=0);
			if(!check(u,v)) break;
			else if(x==1) continue;
			else{
				if(abs(a[u+2]-a[u])<=d&&abs(a[u+3]-a[u])>d&&f(u,v,x)){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
