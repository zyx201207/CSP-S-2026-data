#include<bits/stdc++.h>
using namespace std;
int const A=5e5+5,B=3e5+5;
int n,m;
int cnt;
int arr[A],vis[B],ans[B];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		v.clear();
		for(int j=i;j<=n;++j){
			int y=arr[j];
			if(vis[y]==0){
				v.push_back(y);
				vis[y]=v.size();
				//cout<<y<<' ';
				continue;
			}
			int x=v.back();
			while(x!=y){
				v.pop_back();
				vis[x]=0;
				x=v.back();
			}
			//cout<<endl;
		}
		for(int j=1;j<=m;++j){
			if(vis[j]!=0) ++ans[j];
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
