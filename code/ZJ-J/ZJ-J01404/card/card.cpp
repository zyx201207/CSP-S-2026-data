#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int A[500005];
int ans[300005];
int now[300005];
bool vis[300005];
int cnt;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	if(m==1){
		printf("%d",n);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			if(A[i]!=A[n]) ans[A[i]]++;
		}
		printf("%d %d",ans[1],ans[2]);
	}else{
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=i;j<=n;j++){
				if(vis[A[j]]){
					while(now[cnt]!=A[j]){
						vis[now[cnt]]=0;
						cnt--;
					}
				}else{
					cnt++;
				now[cnt]=A[j];
				vis[A[j]]=true;
				}
			}
			for(int j=1;j<=cnt;j++){
				ans[now[j]]++;
				vis[now[j]]=0;
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}