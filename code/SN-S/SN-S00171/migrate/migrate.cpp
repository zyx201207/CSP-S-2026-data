#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
int n;
ll d;
ll a[15];
ll md[15][15];
ll cnt[15];
ll ans;
void dfs(int st,int x,int len){
	if(len==md[st][x]){
		cnt[x]++;
	}else if(len<md[st][x]){
		cnt[x]=1;
		md[st][x]=len;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(st,i,len+1);
		}else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				md[i][j]=LONG_LONG_MAX;
			}
		}
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof cnt);
			dfs(i,i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		} 
		cout<<ans<<'\n';
	}

	
	return 0;
} 
