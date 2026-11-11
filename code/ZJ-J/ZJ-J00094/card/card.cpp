#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)vis[j]=0;
			stack<int>s;
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					s.push(a[j]);
					vis[a[j]]++;
				}else{
					while(!s.empty()&&s.top()!=a[j]){
						vis[s.top()]--;
						s.pop();
					}
				}
			}
			for(int j=1;j<=m;j++){
				if(vis[j])ans[j]++;
			}
		}
	}else if(m<=2){
		if(m==1){
			cout<<n;
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[n]!=a[i])ans[a[n]]++;
		}
	}else{
		for(int i=1;i<=n;i++){
			ans[a[i]]=max(ans[a[i]],i);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
