#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],mp[300005],mpi[300005],ans[300005];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i]) f=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++) mp[a[i]]++;
		for(int i=1;i<=m;i++){
			ans[i]=ans[i-1]+mp[i];
		}
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		return 0;
	}
	int g=0;
	while(g<=n){
		g++;
		int cnt=0;
		//memset(ans,0,sizeof ans);
		memset(b,0,sizeof b);
		memset(mp,0,sizeof mp);
		for(int o=g;o<=n;o++){
			if(mp[a[o]]==0){
				b[++cnt]=a[o];
				mp[b[cnt]]=1;
				mpi[b[cnt]]=cnt;
			}else{
				for(int p=mpi[a[o]]+1;p<=cnt;p++){
					mp[b[p]]=0;
					b[p]=0;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=m;j++){
				if(b[i]==j) ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
