#include<bits/stdc++.h>
using namespace std;
long long w[500010], k[510],                     a[510][30],               t[510][30];
//DiTieKou->ZhanTing|XianLuJingGuoDiTieZhanGeShu|DiITiaoXianLuDeDiJGeZhan|IXianLu->DiJZhanTing
long long csdbh,n,m,d,q,x,y,ans;
vector<long long> s[500010];
long long v[510][30];
long long zhan(long long aa,long long bb){
	long long i;
	for(i=1;i<=k[aa];i++){
		if(a[aa][i]==bb)break;
	}
	return i;
}
void f(long long xx,long long yy,long long tt){
//	printf("%lld,%lld,%lld\n",xx,yy,tt);
	if(xx==y){
		long long j;
		for(j=1;j<=k[yy];j++){
			if(a[yy][j]==y){
				break;
			}
		}
		ans=min(ans,tt+t[yy][j]);
		return;
	}
	for(long long i=0;i<s[xx].size();i++){
		for(long long j=1;j<=k[s[xx][i]];j++){
			if(s[xx][i]==yy&&v[yy][j]>tt){
				v[yy][j]=tt;
				f(a[yy][j],yy,tt);
			}
			else if(v[s[xx][i]][j]>tt+t[s[xx][i]][j]+t[yy][zhan(yy,xx)]){
				v[s[xx][i]][j]=tt+t[s[xx][i]][j]+t[yy][zhan(yy,xx)];
				f(a[s[xx][i]][j],s[xx][i],v[s[xx][i]][j]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&csdbh,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			s[a[i][j]].push_back(i);
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=k[i];j++){
//			printf("%lld ",t[i][j]);
//		}
//		printf("\n");
//	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=INT_MAX;
		memset(v,0x3f,sizeof(v));
		for(long long i=0;i<s[x].size();i++){
			f(x,s[x][i],w[x]+w[y]+t[s[x][i]][x]);
		}
		printf("%lld\n",ans);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/