#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[300005];
int vis[300005];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]]++;
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==0){
				cnt+=f[a[i]];
				vis[a[i]]++;
				printf("%d ",cnt);
			} 
		}
	}
	else{
		printf("%d ",n);
		for(int i=2;i<=m;i++){
			printf("%d ",n-i+1);
		}
	}
	return 0;
}
