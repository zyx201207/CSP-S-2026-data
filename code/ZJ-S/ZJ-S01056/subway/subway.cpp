#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q;
int w[M];
struct Hall{
	int line,walk;
};
vector <Hall> v[M];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int aij,tij;
			cin>>aij>>tij;
			v[aij].push_back({i,tij});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
//		cout<<"Hall "<<i<<": ";
//		for(int j=0;j<v[i].size();j++)cout<<v[i][j].line<<' ';
//		cout<<'\n';
		for(int j=0;j<v[i].size()-1;j++){
			for(int k=j+1;k<v[i].size();k++){
				int l1=v[i][j].line;
				int l2=v[i][k].line;
				f[l1][l2]=f[l2][l1]=min(f[l1][l2],v[i][j].walk+v[i][k].walk);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int res=1e18;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				res=min(res,w[x]+v[x][i].walk+f[v[x][i].line][v[y][j].line]+v[y][j].walk+w[y]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

/*

I love CCF.

CSP 2026 RP=2147483647

shi guang de he ru hai liu
wo he OI fen tou zou
mei you na nian CSP
shi wan quan de AC
nao hai zhi zhong you yi ge NOIP de qi ji
you wo na bu dao de sheng yi

(ben ren lai zi Wenzhou,yi ge mei you di tie zhi you qing gui de cheng shi,
gang dao Hangzhouxi Railway Station de shi hou,
hai zhuan men yan jiu le yi xia Hangzhou/Hanggang Metro de huan cheng zhi du,
fa xian bu guan ni zai yi tiao xian lu li mian lai hui duo shao ci,
sao ma de shi hou hao xiang zhi kan ni jin zhan he chu zhan de wei zhi.
mei xiang dao CCF ju ran zhen de kao dao le.
zhuan le zhuan le.)

hahahahahahahahahaha,A le.

*/