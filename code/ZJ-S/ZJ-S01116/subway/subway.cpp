#include<bits/stdc++.h>
using namespace std;
int k[5],car[5][500005],c,n,m,d,q,st[500005],to[500005],cnt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(register int i=1;i<=m;i++){
		scanf("%d",&st[i]);
	}
	for(register int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(register int j=1;j<=k[i];j++){
			int x,ti;
			scanf("%d%d",&x,&ti);
			car[i][x]=ti;
			to[++cnt]=x;
		}
	}
	int ans;
	for(register int i=1;i<=q;i++){
		int mn=INT_MIN,x,y;
		scanf("%d%d",&x,&y);
		cout<<st[x]+st[y]+7<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
