#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans;
int a[505];
struct node{
	int x,y,k;
}s[5005][505];
void dfs(int l,int r,long long dis){
	if(l==r){
		ans=min(dis+a[r],ans);
		return ;
	}
	if(l>=r)return ;
	dis+=a[l];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[1][i].k;j++){
			if(l>s[j][i].x)continue;
			if(l==s[j][i].x){
				for(int k=j+1;k<=s[1][i].k&&s[k][i].x<=r;k++)dfs(s[k][i].x,r,dis+s[j][i].y+s[k][i].y);
				break;
			}
		}
		
		
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int k,x,y;cin>>k;
		s[1][i].k=k;
		for(int j=1;j<=k;j++){
			scanf("%d%d",&s[j][i].x,&s[j][i].y);
			
		}
	}
	while(q--){
		ans=10000000000;
		int l,r;
		scanf("%d%d",&l,&r);
		dfs(l,r,0);
		cout<<ans<<endl;
	}
	return 0;
} 


