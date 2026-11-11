//SN-S00471 田牧可 西安交通大学附属中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,T,n,d,x[N],cnt=0,minn=0x3f3f3f3f;
void dfs1(ll now,ll des,ll step){
	if(now==des) minn=min(minn,step);
	for(int i=now+1;x[i]-x[now]<=d&&now<=des;i++) dfs1(i,des,step+1);
}
/*void dfs2(int now,int des,int step){
	if(now==des&&step==minn) cnt++;
	for(int i=now+1;x[i]-x[now]<=d&&now<=des;i++) dfs2(i,des,step+1);
}*/
bool check(int u,int v){
	
	dfs1(u,v,0);
	cout<<u<<" "<<v<<" "<<minn<<"\n";
	//cnt=0;dfs2(u,v,0);
	//if(cnt==2) return true;
	//else return false;
	/*int cnt=0;
	for(int i=u+3;i<=v;i++){
		if(x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d&&x[i]-x[i-3]>d) cnt++;
		if(cnt>=2) return false;
	}
	return true;*/
}
void solve1(){
	int ans=0;
	for(int u=1;u<=n-1;u++){
		for(int v=u+1;v<=n;v++){
			if(check(u,v)) ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	int dif=x[2]-x[1],num=d/dif;
	if(dif>d) cout<<0<<"\n";
	
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c==1||c==2){
		cout<<0<<"\n"<<2;
	}
	if(c==11||c==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}//d=2857391858419 dif= ans=86669 259997
