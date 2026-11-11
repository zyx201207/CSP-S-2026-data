#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],ans,pow2[32];
bool can[N];
void solve_dfs(const int cnt,int now,int p){
	if(n-p+1==cnt){
		if(now==-1){
			now=a[p];
		}
		for(int i=p;i<=n;i++){
			now&=a[i];
		}
		ans=max(ans,now);
		return;
	}
	if(cnt==0){
		ans=max(ans,now);
		return;
	}
	solve_dfs(cnt,now,p+1);
	if(now==-1){
		now=a[p];
	}
	solve_dfs(cnt-1,(now&a[p]),p+1);
}
void solve(){
	int cnt=0;
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&pow2[i])!=0&&!can[j]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=pow2[i];
			for(int j=1;j<=n;j++){
				if((pow2[i]&a[j])==0){
					can[j]=true;
				}
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pow2[0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=30;i++){
		pow2[i]=pow2[i-1]<<1;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		solve_dfs(m,-1,1);
	}
	else if(n>20&&n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,(a[i]&a[j]));
				}
			}
		}
		else solve();
	}
	else solve();
	cout<<ans;
	return 0;
}