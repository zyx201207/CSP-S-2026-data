#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[200010],cnt[5010],ans[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[g[j]]!=0){
				for(int k=cnt[g[j]];k<=j;k++){
					cnt[g[k]]=0;
				}
			}
			cnt[g[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]!=0)	ans[j]++;
		}
		memset(cnt,0,sizeof(cnt));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
