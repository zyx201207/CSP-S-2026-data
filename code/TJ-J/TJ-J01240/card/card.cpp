#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],ans[300005];
bool hs[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20005){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		memset(hs,0,sizeof(hs));
		memset(lst,0,sizeof(lst));
		for(int j=i;j<=n;j++){
			if(hs[a[j]]){
				for(int k=lst[a[j]];k<j;k++){
					hs[a[k]]=0;
				}
			}
			hs[a[j]]=1;
			lst[a[j]]=j;
		}
		for(int j=1;j<=m;j++)ans[j]+=hs[j];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
