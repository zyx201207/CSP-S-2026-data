#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],vh[500010],d[500010],ans[500010];
bool f[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<i<<endl;
	}
	for(int i=n;i>=1;i--){
		if(vh[a[i]]!=0){
			d[i]=vh[a[i]];
		}
		if(vh[a[i]]==0) vh[a[i]]=i;
	}
	for(int p=1;p<=n;p++){
		memset(f,false,sizeof(f));
		int c=p;
		for(int i=p;i<=n;i++){
			if(f[a[i]]==false){
				ans[a[i]]++;
				f[a[i]]=true;
			}
			if(d[i]!=0){
				c=d[i];
				i=c-1;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
