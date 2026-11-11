#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int c,n,m,d,q,s,e,u,ans=0;
int a[N],vis[N][500];
int buhuancheng(int s,int e,int l){
	for(int i=s;i<=e;i++){
		if(vis[l][i]!=0){
			ans+=vis[l][i];
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",d);
		for(int j=1;j<=d;j++){
			scanf("%d",u);
			scanf("%d",vis[u][j]);
		}
	}
	while(q--){
		cin>>s>>e;
		ans=ans+a[s]+a[e];
		for(int i=1;i<=m;i++){
			if(vis[i][s]!=0 && vis[i][e]!=0){
				cout<<buhuancheng(s,e,i);
				break;
			}else{
				cout<<buhuancheng(s,e,i)+17;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
