#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
const int N=5e5+10;
inline int read(){
	char c=getchar();int ans=0,p=1;
	while (c<'0'||c>'9'){if (c=='-') p=-1;c=getchar();}
	while (c>='0'&&c<='9'){ans=ans*10+(c-48);c=getchar();}
	return ans*p;
}
LL w[N];
vector<LL> a[510],b[510];
pll wz[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	LL c=read(),n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=m;i++){
		w[i]=read();
	}
	for (int i=1;i<=n;i++){
		int k;cin>>k;
		for (int j=1;j<=k;j++){
			int x=read(),y=read();
			a[i].push_back(x);
            b[i].push_back(y);
            wz[x]={i,j-1};
		}
	}
	 for (int i=1;i<=q;i++){
		 int l=read(),r=read();
		 pll x=wz[l],y=wz[r];
		 cout<<w[l]+w[r]+b[x.first][x.second]+b[y.first][y.second]<<"\n";
	 }
	 return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
