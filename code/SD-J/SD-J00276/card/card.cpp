#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],pd[500010],lst[300010],ans[300010];
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(lst,0,sizeof lst);
		memset(pd,0,sizeof pd);
		memset(vis,0,sizeof vis);
		long long r=0;
		for(int j=i;j<=n;j++){
			if(lst[a[j]]>0){
				r=lst[a[j]];
				for(int k=lst[a[j]]+1;k<=j;k++){
					lst[pd[k]]=0;
				}
			}
			else{
				pd[++r]=a[j];
				lst[a[j]]=r;
			}
		}
		for(int j=1;j<=r;j++){
			if(vis[pd[j]]==0){
				vis[pd[j]]=1;
				ans[pd[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

