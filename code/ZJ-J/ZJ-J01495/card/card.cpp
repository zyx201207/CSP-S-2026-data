#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010];
vector<int>son[500010],b[300010];
bool vi[500010],brt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])brt=1;
	}
	if(brt){
		for(int i=1;i<=n;i++){
			if(b[a[i]].size()>0){
				for(int k=0;k<b[a[i]].size();k++){
					int t=b[a[i]][k];
					for(int j=t+1;j<=i;j++){
						son[t].push_back(j);
					}
				}
			}
			b[a[i]].push_back(i);
		}
		for(int t=1;t<=n;t++){
			memset(vi,0,sizeof vi);
			for(int i=t;i<=n;i++){
				if(vi[i])continue;
				ans[a[i]]++;
				for(int k=0;k<son[i].size();k++){
					vi[son[i][k]]=1;
				}
			}
		}
	}
	else {
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1])ans[a[i-1]]=i-1;
		}
		ans[a[n]]=n;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
