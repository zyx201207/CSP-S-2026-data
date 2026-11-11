//jinlile,wufazhanshengbaolifen
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int yyj,n,m,d,q,k,st,ed;
int w[N];
vector<int> va[N];
vector<int> vt[N];
int work(int st,int x,int bj,int sum) {
	if(st==ed) return sum+w[ed];
	if(!bj) sum+=vt[x][st];
	for(int i=st+1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(va[j][i]!=0) {
				if(i==x) work(j,i,1,sum+vt[x][i]);
				else work(j,i,0,sum+vt[x][i]);
			} 
		}
	}
}//zhegehanshunabushangfen
int work1(int st,int x) {
	if(va[1][ed]!=0&&va[1][1]!=0) return w[1]+w[ed]+vt[1][1]+vt[1][ed];
	else if(va[2][ed]!=0&&va[2][1]!=0) return cout<<w[1]+w[ed]+vt[2][1]+vt[2][ed];
	else if(va[1][ed]!=0&&va[1][1]==0){ 
		for(int i=1;i<=m;i++) {
			if(va[1][i]!=0&&va[2][1]!=0) return w[1]+w[ed]+vt[2][1]+vt[2][i]+vt[1][i]+vt[1][ed];
		}
	}else if(va[2][ed]!=0&&va[2][1]==0){ 
		for(int i=1;i<=m;i++) {
			if(va[1][i]!=0&&va[2][1]!=0) return w[1]+w[ed]+vt[1][1]+vt[1][i]+vt[2][i]+vt[2][ed];
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);freopen("subway.out","w",stout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>yyj>>n>>m>>d>>q;
	if(n<=2) {
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++) {
			cin>>k;
			for(int j=1;j<=k;j++) {
				int aa,t;cin>>aa>>t;
				va[i].push_back(aa);vt[i].push_back(t);
			}
		}
		while(q--) {
			cin>>st>>ed;
			cout<<work1()<<"\n";
		}	
	} 
	else {//nabushangfen
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++) {
			cin>>k;
			for(int j=1;j<=k;j++) {
				int aa,t;cin>>aa>>t;
				va[i].push_back(aa);vt[i].push_back(t);
			}
		}
		while(q--) {
			cin>>st>>ed;
			for(int i=1;i<=n;i++) {
				if(va[i][st]!=0) {
					cout<<work(st,i,0,w[i])<<"\n";
					break;
				}
			}
		}
	}
	return 0;
} 
