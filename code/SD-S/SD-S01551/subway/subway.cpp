#include<bits/stdc++.h>
using namespace std;
long long qkread() {
	long long n1=0,qkf=1;
	char qkc=getchar();
	while(qkc<'0'||qkc>'9') {
		if(qkc=='-') qkf=-1;
		qkc=getchar();
	}
	while(qkc>='0'&&qkc<='9') {
		n1=n1*10+qkc-48;
		qkc=getchar();
	}
	return n1*qkf;
}
long long c,n,m,D,q,w[500001],cn,cn2,cn3,ans,f[500001];
vector<pair<int,long long> > wy[501];
int cnt;
vector<pair<int,long long> > ug[500001];
map<int,int> idug[500001];
void dfs(long long num,int now,int lst) {
	if(now==cn2) {
		ans=min(num+ug[now][idug[now][lst]].second,ans);
		return;
	}
	for(int i=0; i<ug[now].size(); i++) {
		pair<int,int> ln=ug[now][i];
		for(int j=0; j<wy[ln.first].size(); j++) {
			int to=wy[ln.first][j].first;
			if(!f[to]) {
				f[to]=1;
				if(ln.first!=lst) {
					if(now==cn) dfs(num+ln.second,to,ln.first);
					else dfs(num+ug[now][idug[now][lst]].second+ln.second,to,ln.first);
				}
				f[to]=0;
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=qkread(),n=qkread(),m=qkread(),D=qkread(),q=qkread();
	for(int i=1; i<=m; i++) w[i]=qkread();
	for(int i=1; i<=n; i++) {
		cnt++;
		cn=qkread();
		for(int i=1; i<=cn; i++) {
			cn2=qkread(),cn3=qkread();
			wy[cnt].push_back(make_pair(cn2,cn3));
			ug[cn2].push_back(make_pair(cnt,cn3));
			idug[cn2][cnt]=ug[cn2].size()-1;
		}
	}
	while(q--) {
		memset(f,0,sizeof(f));
		ans=9223372036854775807ll;
		cn=qkread(),cn2=qkread();
		f[cn]=1;
		dfs(w[cn]+w[cn2],cn,0);
		cout<<ans<<"\n";
	}
	return 0;
}
