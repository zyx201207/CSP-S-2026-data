#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll n,k;
ll a[N];
void solve1(){
	ll d,f;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d=a[2]-a[1];
	f=k/d;
	if(f<=1){
		cout<<"0\n";
		return ;
	}
	cout<<max(0ll,n-(f+f-1))<<'\n';
	return ;
}
ll mn[301][301],cnt[301][301];
void dfs(int st,int x,int step){
	if(mn[st][x]==step){
		cnt[st][x]++;
	}
	if(mn[st][x]>step){ 
		mn[st][x]=step;
		cnt[st][x]=1;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]>k)break;
		dfs(st,i,step+1);
	}
	return ;
}
ll ans=0;
void solve2(){
	ans=0;
	cin>>n>>k;
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
		for(int j=i;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		if(11<=C&&C<=12){
			solve1();
		}//8pts
		else{
			solve2(); 
		}//8pts
	} 
	return 0;
}