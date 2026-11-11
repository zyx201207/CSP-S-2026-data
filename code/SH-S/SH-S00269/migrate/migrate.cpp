#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans=0,Min=0x3f3f3f3f;
long long mp[2000005];
void dfs(int x,int cnt,int end){
	if(x==end){
		if(cnt<Min){
			Min=cnt;
			ans=1;
		}
		else if(cnt==Min){
			ans++;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(mp[i]-mp[x]>d) break;
		dfs(i,cnt+1,end);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int abc=1;abc<=t;abc++){
		int ANS=0;
		cin>>n>>d;
		memset(mp,0,sizeof mp);
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				Min=0x3f3f3f3f;
				dfs(i,0,j);
				if(ans==2) ANS++;
			}
		}
		cout<<ANS<<endl;
	}
	return 0;
}
