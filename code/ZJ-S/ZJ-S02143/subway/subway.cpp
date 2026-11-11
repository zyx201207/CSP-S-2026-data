#include<bits/stdc++.h>
#define int long long
#define U(a,b,c) for(int a=b;a<=c;a++)
#define D(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=5e5+10,M=5e5+10;
int a[N],n,m;
int weight[M];
vector<pair<int,int> > edge[N];
int f[510][510];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	U(i,1,n) f[i][i]=0;
	U(i,1,m) cin>>weight[i];
	U(i,1,n){
		int len;
		cin>>len;
		U(j,1,len){
			int To,val;
			cin>>To>>val;
			edge[To].push_back(make_pair(i,val));
		}
	}
	U(i,1,m){
		if(edge[i].empty()) continue;
		U(j,0,edge[i].size()-1){
			U(k,0,edge[i].size()-1){
				if(j==k) continue;
				int Way1=edge[i][j].first,Val1=edge[i][j].second,Way2=edge[i][k].first,Val2=edge[i][k].second;
				f[Way1][Way2]=min(f[Way1][Way2],Val1+Val2);
				f[Way2][Way1]=min(f[Way2][Way1],Val2+Val1);
			}
		}
	}
	U(k,1,n)
		U(i,1,n)
			U(j,1,n)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(p--){
		int To1,To2,ans=0x3f3f3f3f3f3f3f3f;
		cin>>To1>>To2;
		U(i,0,edge[To1].size()-1)
			U(j,0,edge[To2].size()-1){
				ans=min(ans,f[edge[To1][i].first][edge[To2][j].first]+weight[To1]+edge[To1][i].second+weight[To2]+edge[To2][j].second);
			}
		cout<<ans<<"\n";
	}
	return 0;
}