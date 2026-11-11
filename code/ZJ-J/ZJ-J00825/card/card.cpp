#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010];
int ans[300010],mp[500010];
map<int,int> f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1){
			f1=0;
		}
	}
	if(f1){
		for(int i=n;i>=n-m+1;i--){
			cout<<n<<' ';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[a[j]]=0;
				f[a[j]]=0;
			}
			for(int j=i;j<=n;j++){
				if(mp[a[j]]){
					for(int k=mp[a[j]]+1;k<j;k++){
						f[a[k]]=1;
					}
					mp[a[j]]=j;
				}
				else{
					mp[a[j]]=j;
				}
			}
			for(int j=i;j<=n;j++){
				if(!f[a[j]])ans[a[j]]++,f[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
