//ZHS 00446 
#include<bits/stdc++.h>
#define int long long
#define maxn 500505
#define maxm 1005
#define INF 1145141919819
using namespace std;
int c,n,m,d,q,w[maxn],k[maxm];
vector<int>a[maxm],t[maxm],ans[maxm][maxm];
vector<pair<int,int> >ro[maxn];
int rro[maxm][maxm];
void build(int now){
	vector<int>v;
	for(auto a:ro[now]){
		int nn=a.first,len=a.second;
		for(auto b:ro[nn]){
			int nnn=b.first,ll=len+b.second;
			if(nnn!=now)
				rro[now-n][nnn-n]=ll;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
//	cout<<1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)rro[i][j]=INF;
	for(int i=1;i<=m;i++){
		cin>>k[i];
		int iin;
		for(int j=1;j<=k[i];j++){
			cin>>iin;
			a[i].push_back(iin);
			cin>>iin;
			t[i].push_back(iin);
			ro[n+i].push_back({a[i][j-1],iin});
			ro[a[i][j-1]].push_back({n+i,iin});
		}
	}
	for(int i=1;i<=m;i++)
		build(n+i);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				if(i==j)continue;
				rro[i][j]=rro[j][i]=min(rro[i][j],rro[i][k]+rro[j][k]);
			}
		}
	}
	int l,r;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		int aans=INF;
		for(auto a:ro[l])
			for(auto b:ro[r]){
				aans=min(aans,rro[a.first-n][b.first-n]+a.second+b.second);
			}
		cout<<aans+w[l]+w[r]<<"\n";
	}
	return 0;
}
