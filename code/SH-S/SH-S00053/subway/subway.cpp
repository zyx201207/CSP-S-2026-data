#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 510;
const int MAXM = 5e5 + 10;
const int MAXQ = 1e5 + 10;
const int MAXK = 5e5 + 10;

int c,n,m,d,q;
int w[MAXM];
struct line{
	int k;
	int a[MAXK];
	int t[MAXK];
}l[MAXN];
int ans;

void solve(int s,int e,int cnt){
	if(s == e){
		ans = cnt;
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= l[i].k;j++){
			if(l[i].a[j] == e){
				solve(s,l[i].a[j],cnt + l[i].t[j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> l[i].k;
		for(int j = 1;j <= l[i].k;j++){
			cin >> l[i].a[j] >> l[i].t[j];
		}
	}
	for(int i = 1;i <= q;i++){
		int start,end;
		ans = 0;
		cin >> start >> end;
		solve(start,end,0);
		cout << ans << endl;
	}
	
	return 0;
}
