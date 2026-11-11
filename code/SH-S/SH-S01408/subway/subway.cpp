#include<bits/stdc++.h>
#define int long long
#define N 500009
#define M 509
#define high 1e9+7
#define check cout<<"ok"<<endl
using namespace std;
int c,n,m,d,q,INF=high;
int w[N],a[M][M];
vector<int> s[N],t[N];
int mmin(int a,int b){return (a<b?a:b);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	INF*=INF;
	memset(a,INF,sizeof(a));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int sz,a1,t1;
		cin>>sz;
		for(int j=1;j<=sz;j++){
			cin>>a1>>t1;
			s[a1].push_back(i);
			t[a1].push_back(t1);
		}
	}
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<s[i].size();j++)
			for(int k=j+1;k<s[i].size();k++){
				a[s[i][j]][s[i][k]]=mmin(a[s[i][j]][s[i][k]],t[i][j]+t[i][k]);
				a[s[i][k]][s[i][j]]=mmin(a[s[i][k]][s[i][j]],t[i][j]+t[i][k]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				a[j][k]=mmin(a[j][k],a[j][i]+a[i][k]);
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		int ans=INF;
		ans*=ans;
		for(int j=0;j<s[st].size();j++)
			for(int k=0;k<s[ed].size();k++)
				ans=mmin(ans,t[st][j]+t[ed][k]+a[s[st][j]][s[ed][k]]);
		cout<<ans+w[st]+w[ed]<<endl;
	}
	return 0;
}

