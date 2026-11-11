#include<bits/stdc++.h>
using namespace std;
const long long MI = 4611686018427387904;
long long c,n,m,d,q,bg,ed,ans,mi;
bool f[510];
inline long long read(){
	long long x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
long long xc,jgz,jzs,zjc;
long long xj[510][510];
struct xl{
	int xs;
	vector<int> jgx;
}b[510];
struct zd{
	long long gys;
	int xls;
	int jg[25];
	int jgc[25];
}a[500010];
void zdl(int o){
	pair<long long,int>p(0,o);
	priority_queue< pair<long long,int>,vector<pair<long long,int> >,greater< pair<long long,int> > > qq;
	qq.push(p);
	while(!qq.empty()){
		auto ff = qq.top().first;
		auto ss = qq.top().second;
		qq.pop();
		if(xj[o][ss] == 0){
			xj[o][ss] = ff;
			xj[ss][o] = ff;
		}
		if(xj[o][ss] < ff){
			continue;
		}
		xj[o][ss] = ff;
		xj[ss][o] = ff;
		for(auto jx:b[o].jgx){
//			if(xj[o][jx] > xj[o][ss] + xj[ss][jx]){
//				xj[o][jx] = xj[o][ss] + xj[ss][jx];
//				xj[jx][o] = xj[o][ss] + xj[ss][jx];
//			}
			if(jx == ss)continue;
			
			pair<long long,int>p(xj[o][ss] + xj[ss][jx],jx);
			qq.push(p);
		}
	}
}
//void zdl1(int o,int p){
//	for(auto xd:b[o].jgx){
//		zdl1(xd);
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1;i <= m;i++){
		a[i].gys = read();
		a[i].xls = 0;
	}
	for(int i = 1;i <= n;i++){
		xc = read();
		for(int j = 1;j <= xc;j++){
			jgz = read();
			jzs = read();
			for(int k = 1;k <= a[jgz].xls;k++){
				zjc = a[jgz].jgc[k] + jzs;
				if(xj[a[jgz].jg[k]][i] == 0){
					xj[a[jgz].jg[k]][i] = zjc;
					xj[i][a[jgz].jg[k]] = zjc;
					b[a[jgz].jg[k]].xs++;
					b[a[jgz].jg[k]].jgx.push_back(i);
					b[i].xs++;
					b[i].jgx.push_back(a[jgz].jg[k]);
				}
				else if(zjc < xj[a[jgz].jg[k]][i]){
					xj[a[jgz].jg[k]][i] = zjc;
					xj[i][a[jgz].jg[k]] = zjc;
				}
			}
			a[jgz].xls++;
			a[jgz].jg[a[jgz].xls] = i;
			a[jgz].jgc[a[jgz].xls] = jzs;
//			printf("%d %d\n",a[jgz].jg[a[jgz].xls],a[jgz].jgc[a[jgz].xls]);
		}
	}
	for(int i = 1;i <= q;i++){
		bg = read();
		ed = read();
		ans = a[bg].gys + a[ed].gys;
		mi = MI;
		for(int j = 1;j <= a[bg].xls;j++){
			if(!f[a[bg].jg[j]]){
//				cout << "asdf\n";
				zdl(a[bg].jg[j]);
				f[a[bg].jg[j]] = 1;
			}
			for(int k = 1;k <= a[ed].xls;k++){
				
				mi = min(mi,a[bg].jgc[j] + xj[a[bg].jg[j]][a[ed].jg[k]] + a[ed].jgc[k]);
//				printf("%lld %lld %lld\n",a[bg].jgc[j],xj[a[bg].jg[j]][a[ed].jg[k]],a[ed].jgc[k]);
			}
			
		}
		ans = ans + mi;
		printf("%lld\n",ans);
	}
} 
