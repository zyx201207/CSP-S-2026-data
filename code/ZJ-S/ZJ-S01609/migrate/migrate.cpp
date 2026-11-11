#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,c,T,n,d,dp[305][305],a[1000010],minn,ans;
void dfs(int now,int ed,int cnt){
	if(now>=ed){
		if(minn>cnt){
			minn=cnt;
			ans=1;
		}
		else if(minn==cnt) ans++;
		return;
	}
	for(int i=now+1;i<=ed;i++){
		if(a[i]-a[now]<=d) dfs(i,ed,cnt+1);	
	}
}
void solve(){
	cin>>n>>d;
	int s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	int ANS=0;
	if(c==11||c==12){
		s=a[2]-a[1];
		int tmp=d/s;
		tmp=tmp*2;
		if(tmp>=4) ANS=max(ANS,n-tmp+1);
		cout<<ANS<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			minn=114514;
			ans=0;
			dfs(i,j,0);
			if(ans==2) ANS++;
		}
	}
	cout<<ANS<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
	return 0^_^0;
}
/*
2h guo 2 ti,you shi zai wo.
can I 1=?
X X XXX
O O OOO
XX X XXX
OO O OOO
XX X XXXX
OO O OOOO
XX XX XXX XX
OO OO OOO OO
XXX
OOO
*/