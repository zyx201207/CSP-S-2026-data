#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=2e5+10;
queue<int>p;
int n,w[N],s[M],fi[M],k[N],t[502][4000],rd[N],ss[N],S[N],cnt,c,m,d,q,li;
vector<int>a[N];
vector<int>f[N];
long long xx(int x,int y){
	if(f[x][0]==f[y][0])return f[x][0];
	if(f[x][1]==f[y][0])return f[x][1];
	if(f[x][0]==f[y][1])return f[x][0];
	if(f[x][1]==f[y][1])return f[x][1];
	return 1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>k[i]>>x>>t[i][1];
		int lx=x;
		for(int j=2;j<=k[i];j++){
			cin>>x>>t[i][j];
			a[lx].push_back(x);
			f[x].push_back(i);
			lx=x;
			rd[x]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>fi[i];
	}
	//if(c>=7&&c<=11){
		int x;
		for(int i=1;i<=m;i++){
			if(rd[i]==0)x=i;
		}
		f[0][0]=f[x][0];
		li=0;
		for(int i=x;i;i=a[i][0]){
			S[i]=++cnt;
			ss[cnt]=ss[cnt-1]+t[xx(li,i)][i]+t[xx(i,a[i][0])][i];
			i=li;
		}
		for(int i=1;i<=q;i++){
			int X=S[s[i]],Y=S[fi[i]];
			if(X>Y)swap(X,Y);
			cout<<ss[Y]-ss[x-1]+w[s[i]]+w[fi[i]]<<"\n";
		}
	//}
	return 0;
}
