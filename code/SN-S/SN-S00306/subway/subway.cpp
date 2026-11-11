#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
int k[510];
long long t[510][20010];
vector<int> ki[510];
int flag[510];
int num[500010];
long long ans[100010];
void f(int x,int y,long long tm,int l){
	for (int i=1;i<=n;i++){
		if (t[i][x]!=-1 && t[i][y]!=-1){
			if (tm+t[i][y]+t[i][x]<ans[l] || ans[l]==0){
				ans[l]=tm+t[i][y]+t[i][x];
			}
			return;
		}
	}
	for (int i=1;i<=n;i++){
		if (t[i][x]!=-1 && flag[i]==0){
			flag[i]=1;
			for (int j=1;j<=k[i];j++){
				if (num[ki[i][j-1]]>=2 && ki[i][j-1]!=x){
					f(ki[i][j-1],y,tm+t[i][x]+t[i][ki[i][j-1]],l);
				}
			}
			flag[i]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		memset(t[i],-1,sizeof(t[i]));
		for (int j=1;j<=k[i];j++){
			int x;
			scanf("%d",&x);
			num[x]++;
			ki[i].push_back(x);
			scanf("%lld",&t[i][x]);
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(flag,0,sizeof(flag));
		f(x,y,0,i);
		ans[i]+=w[x]+w[y];
	}
	for (int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
