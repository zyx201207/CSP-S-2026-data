#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct nd{
	ll v,w;
};
ll ptidxx;
ll c,n,m,d,q,w[500005],k[505],t[505][50005],a[505][50005];
ll dg[500005],ed[500005],cntpt,is[500005],dd[5005][5005];
ll bl[500005],tmm[500005],ptt[505][50005];
vector<nd>pths[505];
void fld(){
	for(ll k=1;k<=cntpt;k++){
		for(ll i=1;i<=cntpt;i++){
			if(k==i)continue;
			for(ll j=1;j<=cntpt;j++){
				if(k==j)continue;
				if(i==j)continue;
				dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	memset(dd,0x3f,sizeof dd);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dg[a[i][j]]++;
			if(j!=1||j!=k[i])dg[a[i][j]]++;
		}
	}
	for(ll i=1;i<=n;i++){
		ll idx=0;
		for(ll j=1;j<=k[i];j++){
			if(j==1||dg[a[i][j]]!=2||j==k[i]){
				pths[i].push_back({i,j});
				ed[++idx]=j;
				is[a[i][j]]=1;
			}else{
				bl[a[i][j]]=i;
				tmm[a[i][j]]=t[i][j];
			}
		}
	}
	for(ll i=1;i<=m;i++)if(is[i])is[i]=++cntpt;
	for(ll i=1;i<=n;i++){
		ll idx=0;
		for(ll j=1;j<=k[i];j++){
			if(j==1||dg[a[i][j]]!=2||j==k[i])ptt[i][++idx]=a[i][j];
		}
		for(ll j=1;j<idx;j++){
			for(ll jj=j+1;jj<=idx;jj++){
				dd[is[ptt[i][jj]]][is[ptt[i][j]]]=min(dd[is[ptt[i][jj]]][is[ptt[i][j]]],t[i][j]+t[i][jj]);
				dd[is[ptt[i][j]]][is[ptt[i][jj]]]=min(dd[is[ptt[i][j]]][is[ptt[i][jj]]],t[i][j]+t[i][jj]);
			}
		}
	}
	fld();
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll addd=w[x]+w[y];
		if(is[x]){
			if(is[y]){
				cout<<dd[is[x]][is[y]]+addd<<"\n";
			}else{
				ll mi=1e18;
				for(nd v:pths[bl[y]]){
					ll tmppp=dd[is[x]][is[a[v.v][v.w]]]-t[v.v][v.w]+tmm[y];
					mi=min(mi,tmppp);
				}
				cout<<mi+addd<<"\n";
			}
		}else{
			if(is[y]){
				ll mi=1e18;
				for(nd v:pths[bl[x]]){
					ll tmppp=dd[is[y]][is[a[v.v][v.w]]]-t[v.v][v.w]+tmm[x];
					mi=min(mi,tmppp);
				}
				cout<<mi+addd<<"\n";
			}else{
				ll mi=1e18;
				for(nd v:pths[bl[x]]){
					for(nd vv:pths[bl[y]]){
						ll tmppp=dd[is[a[vv.v][vv.w]]][is[a[v.v][v.w]]]-t[v.v][v.w]+tmm[x]-t[vv.v][vv.w]+tmm[y];
						mi=min(mi,tmppp);
					}
				}
				cout<<mi+addd<<"\n";
			}
		}
	}//*/
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
