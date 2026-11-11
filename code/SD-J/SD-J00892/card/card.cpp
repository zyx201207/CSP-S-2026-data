#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],ans[20];
bool f[20];
int cnt[20];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) f[i]=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]==1]){
				for(int q=cnt[a[j]];q<j;i++) f[a[q]]=0;
			}
			f[a[j]]=1;
			cnt[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(f[j]) ans[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
