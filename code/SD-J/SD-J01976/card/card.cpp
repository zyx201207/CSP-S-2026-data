#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans[N];
map<int,int> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			int w=i;
			for(int j=i;j<=n;j++){
				if(mp.count(a[j])&&mp[a[j]]!=0){
					for(int k=mp[a[j]];k<j;k++) mp[a[k]]=0;
					mp[a[j]]=++w;
				}
				else mp[a[j]]=w,w++;
			}
			for(int j=i;j<=n;j++) if(mp[a[j]]!=0) ans[a[j]]++,mp[a[j]]=0;
		}
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]) printf("%d ",min(i,n));
		}
	}
	return 0;
}
