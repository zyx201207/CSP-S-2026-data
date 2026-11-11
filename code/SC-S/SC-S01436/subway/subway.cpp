#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,len,a[2006],db[2006];
int cz(int x){
	if(db[x]==x) return x;
	return db[x]=cz(db[x]);
}
struct subway{
	int x,y,c;
}b[2006];
bool cmp(subway x,subway y){
	return x.c<y.c;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		db[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int xb=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[xb].y>>b[xb].c;
			b[xb].x=i;
			xb++;
		}
	}
	sort(b,b+xb-1,cmp);
	for(int i=1;i<=q;i++){
		int begin,end;
		cin>>begin>>end;
		for(int i=0;i<xb;i++){
			int xb=cz(b[i].x),yb=cz(b[i].y);
			if(xb!=yb){
				db[b[i].x]=b[i].y;
				len+=(c+a[i]);
			}
			if(db[begin]==db[end]) break;
		}
		cout<<len+a[1]<<'\n';
		len=0;
		for(int i=1;i<=m;i++){
			db[i]=i;
		}
	}
	return 0;
}