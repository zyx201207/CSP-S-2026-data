#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c,n,m,d,q;
struct sta_linenode{
	int linenum;
	ll intotime;
};
struct stonline{
	int stanum;
	ll intotime;
};
ll hctime[505][505];
vector<stonline> line[505];
int outtime[500005];
vector<sta_linenode> lineofst[500005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&outtime[i]);
	}
	for(int i=1;i<=n;i++){
		int k,__a,__t;
		sta_linenode __s_l;
		stonline __stonl;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&__a,&__t);
			__s_l.linenum=i;
			__s_l.intotime=__t;
			__stonl.stanum=__a;
			__stonl.intotime=__t;
			lineofst[__a].push_back(__s_l);
			line[i].push_back(__stonl);
		}
	}
	memset(hctime,0x3f,sizeof(hctime));
	for(int i=1;i<=m;i++){
		if(lineofst[i].size()>1){
			//换乘站
			for(auto j:lineofst[i]){
				for(auto l:lineofst[i]){
					if(l.linenum==j.linenum) continue;
					hctime[l.linenum][j.linenum]=min(hctime[l.linenum][j.linenum],l.intotime+j.intotime);
				}
			}
		}
	}
	//floid(O(n^3))
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				hctime[i][j]=hctime[j][i]=0;
				continue;
			}
			for(int k=1;k<=n;k++){
				hctime[i][j]=min(hctime[i][j],hctime[i][k]+hctime[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int start,to;
		scanf("%d%d",&start,&to);
		ll Min=0x3f3f3f3f3f3f3f3f;
		for(auto l:lineofst[start]){
			for(auto r:lineofst[to]){
				Min=min(Min,hctime[l.linenum][r.linenum]+l.intotime+r.intotime);
			}
		}
		printf("%lld\n",Min+outtime[start]+outtime[to]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*


*/