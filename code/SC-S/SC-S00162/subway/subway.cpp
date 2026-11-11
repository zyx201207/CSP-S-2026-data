#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int c,n,m,d,q;
int w[N],t[N],walkin[N],cnt[N];
vector<int> id[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int tt,aa;
			scanf("%d%d",&aa,&tt);
			id[aa].push_back(i);
		}
			printf("%d",0);
		
	}
	fclose(stdin),fclose(stdout);
	return 0;
}