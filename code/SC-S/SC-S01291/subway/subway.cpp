#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],x,y,ans,k[505];
bool ust[500005];
vector<int> sli[500005];
struct subway{
	int sta;
	int t;
}a[505][500005];
void solve(int line,int staid,int stanum,long long time){
	if(a[line][stanum].sta==x&&sli[staid].size()==1){
		time+=w[staid]+a[line][stanum].t;
	}
	if(a[line][stanum].sta==y){
		ans=min(ans,time+w[a[line][stanum].sta]+a[line][stanum].t);
		return;
	}
	if(sli[staid].size()>1){
		for(int i=0;i<sli[staid].size();i++){
			solve(sli[staid][i],a[sli[staid][i]][stanum+1].sta,stanum+1,time+a[line][stanum].t+a[sli[staid][i]][stanum].t);
		}
	}
	else{
		solve(line,a[line][stanum+1].sta,stanum+1,time);
	}
}
int calc(int line,int station){
	for(int i=1;i<=k[line];i++){
		if(a[line][i].sta==station){
			return i;
		}
	}
	return -1;
}
int main(){
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j].sta >> a[i][j].t;
			sli[a[i][j].sta].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		ans=1e18;
		solve(sli[x][0],x,calc(sli[x][0],x),0);
		cout << ans << '\n';
	}
	return 0;
} 