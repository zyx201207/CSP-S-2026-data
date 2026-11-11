#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=510,M=50010;
int c,n,m,d,q;
int w[M];
int v[M];
int a[N][M];
int t[N][M];
int k[N];
struct edge{
	int tot=0;
	int who[N][2];
}s[M];

int bfs(int st,int ed,int used,int line){
	if(line==0){
		used+=w[st];
		int p=LLONG_MAX;
		int at=0;
		for(int i=1;i<=s[st].tot;i++){
			used+=t[s[st].who[i][0]][s[st].who[i][1]];
			p=min(p,bfs(st,ed,used,s[st].who[s[st].tot][0]));
			used-=t[s[st].who[i][0]][s[st].who[i][1]];
			//cout<<"Continued"<<endl;
		}
		return p;
	}
	if(line&&st==ed){
		used+=w[ed];
		return used;
	}
	int out=LLONG_MAX;
	int qp=used;
	for(int i=1;i<=k[line];i++){
		if(a[line][i]==ed){
			return bfs(ed,ed,used,line);
		}
		for(int j=1;j<=s[a[line][i]].tot;j++){
			if(s[a[line][i]].who[i][0]!=line){//»»³Ë 
				used+=t[line][i];
				used+=t[s[a[line][i]].who[i][0]][s[a[line][i]].who[i][1]];
				out=min(out,bfs(a[s[a[line][i]].who[i][0]][s[a[line][i]].who[i][1]],ed,used,s[a[line][i]].who[i][0]));
				used=qp;
			}
			else continue;//²»»»³Ë 
		}
	}
	return out;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]].tot++;
			s[a[i][j]].who[s[a[i][j]].tot][0]=i;
			s[a[i][j]].who[s[a[i][j]].tot][1]=j;
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		//cout<<t[s[st].who[s[st].tot][0]][s[st].who[s[st].tot][1]]<<endl;
		cout<<bfs(st,ed,0,0);
	}
	return 0;
}
