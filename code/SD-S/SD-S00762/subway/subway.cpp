#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int wal[500010];
int k,a,t;
struct node{
	int v;
	int w;
};
vector<node>e[500010];
long long f[501][501];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wal[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({m+i,t});
		}
	}
	node b1,b2;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=1;j<e[i].size();j++){
			b1=e[i][j];
			for(int g=0;g<j;g++){
				b2=e[i][g];
				int val=b1.w+b2.w;
				int st=b1.v-m;
				int en=b2.v-m;
				if(val<f[st][en]){
					f[st][en]=val;
					f[en][st]=val;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int g=1;g<=n;g++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				long long val=f[i][g]+f[g][j];
				if(f[i][j]>val){
					f[i][j]=val;
					f[j][i]=val;
				}
			}
		}
	}
	long long ans,cnt;
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		ans=LONG_LONG_MAX;
		long long val;
		for(int j=0;j<e[st].size();j++){
			for(int g=0;g<e[en].size();g++){
				b1=e[st][j];
				b2=e[en][g];
				val=b1.w+b2.w+f[b1.v-m][b2.v-m];
				if(val<ans)ans=val;
			}
		}
		cout<<ans+wal[st]+wal[en]<<endl;
	}
	return  0;
}

