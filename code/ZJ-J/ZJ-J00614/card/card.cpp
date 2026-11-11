#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010],ans[500010],cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				int k=j-1;
				while(1){
					cnt[a[k--]]--;
					if(a[k]==a[j])break;
				}
			}cnt[a[j]]++;
		}for(int j=1;j<=m;j++){
			if(cnt[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

