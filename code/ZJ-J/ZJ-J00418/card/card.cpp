#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]==1){
				int k=j-1;
				while(a[k]!=a[j]){
					t[a[k]]=0;
					k--;
				}
			}
			t[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=t[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}