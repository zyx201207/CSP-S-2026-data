#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+6;
int c,t;
int n,d,x[N],mins = INT_MAX;
void dfs(int now,int end,int cnt){
	if(now==end) {mins = min(mins,cnt);return;}
	for(int i = now+1;i<=end;i++){
		if(x[i]-x[now]<=d){
			dfs(i,end,cnt+1);
		}
	}
}
int ans = 0,cn = 0;
void dfs2(int now,int end,int cnt){
	if(now==end) {cn+=(cnt==mins);return;}
	for(int i = now+1;i<=end;i++){
		if(x[i]-x[now]<=d){
			dfs2(i,end,cnt+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans = 0;
		for(int i = 1;i<=n;i++) cin>>x[i];
		if(c!=1 && c!=2 && c!=0){
			cout<<0<<"\n";
			continue;
		}
		for(int len = 2;len<=n;len++){
			for(int i = 1;i<=n-len+1;i++){
				mins = INT_MAX;
				dfs(i,i+len-1,0);
				cn = 0;
				dfs2(i,i+len-1,0);
				if(cn==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
