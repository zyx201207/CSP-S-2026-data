#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+24,M=3e5+24;
int n,m;
int a[N];
int ans[M];
void JOKER_A(){
	int rv=0,cnt=1,last=0;
	for(int i=2;i<=n+1;i++){
		if(a[i-1]==a[i])cnt++;
		else{
			cout<<last+cnt<<" ";
			last+=cnt;
			cnt=1;
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	bool OK_A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		OK_A=(OK_A&&a[i]>=a[i-1]);
	}	
	
	if(OK_A){
		JOKER_A();
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		vector<int> cnt(m+2,0);
		vector<int> vis(n+2,0);
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]>0){
				int t=j-1;
				while(t>0&&(a[t]!=a[j]||vis[t])){
					if(vis[t]){
						t--;
						continue;
					}
					cnt[a[t]]--;
					vis[t--]=1;
				}
				if(!vis[t]){
					cnt[a[t]]--;
					vis[t--]=1;	
				}
			}
			cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=cnt[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
