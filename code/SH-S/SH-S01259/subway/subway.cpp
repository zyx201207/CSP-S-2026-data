#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],f[505][505];
vector<pair<long long,long long> >tz[500010];

long long rl(){
	bool fl=0;
	long long nc=0;
	char ch=getchar();
	if(ch=='-') fl=1;
	else nc+=ch-'0';
	ch=getchar();
	while('0'<=ch&&ch<='9'){
		nc*=10;
		nc+=ch-'0';
		ch=getchar(); 
	}
	return fl ? -nc : nc;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	c=rl();n=rl();m=rl();d=rl();q=rl();
	for(int i=1;i<=m;i++) w[i]=rl();
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		long long x=rl();
		long long y,z;
		for(int j=1;j<=x;j++){
			y=rl();z=rl();
			tz[y].push_back(make_pair(i,z));
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<tz[i].size();j++) for(int k=0;k<j;k++){
		f[tz[i][j].first][tz[i][k].first]=f[tz[i][k].first][tz[i][j].first]=min(f[tz[i][j].first][tz[i][k].first],tz[i][j].second+tz[i][k].second);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=0;i<q;i++){
		long long x=rl(),y=rl(),ans=1000000000000000000ll;
		for(int j=0;j<tz[x].size();j++) for(int k=0;k<tz[y].size();k++){
			ans=min(ans,f[tz[x][j].first][tz[y][k].first]+tz[x][j].second+tz[y][k].second);
			//cout<<tz[x][j].first<<" "<<tz[y][k].first<<" "<<f[tz[x][j].first][tz[y][k].first]+tz[x][j].second+tz[y][k].second<<endl;
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
