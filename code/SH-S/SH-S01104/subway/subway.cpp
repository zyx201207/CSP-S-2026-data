#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dis[505][505],w[500005];
vector<pair<int,long long> > st[500005];
vector<pair<int,long long> > mp[505];
long long qread(){
	char c=getchar();
	int flag=1;
	long long x=0;
	if(c=='-'){
		flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return flag*x;
}
void qwrite(long long ans){
	string s="";
	while(ans!=0){
		char c=ans%10+'0';
		ans/=10;
		s=c+s;
	} 
	for(int i=0;i<s.size();i++){
		putchar(s[i]);
	}
	putchar('\n');
}
void solve(){
	n=qread();
	m=qread();
	d=qread();
	q=qread();
	for(int i=1;i<=m;i++){
		w[i]=qread();
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		k=qread();
		for(int j=1;j<=k;j++){
			a=qread();
			t=qread();
			st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			for(int k=j+1;k<st[i].size();k++){
				dis[st[i][j].first][st[i][k].first]=min(st[i][j].second+st[i][k].second,dis[st[i][j].first][st[i][k].first]);
				dis[st[i][k].first][st[i][j].first]=dis[st[i][j].first][st[i][k].first];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		x=qread();
		y=qread();
		long long ans=1e18;
		for(int i=0;i<st[x].size();i++){
			for(int j=0;j<st[y].size();j++){
				ans=min(ans,st[x][i].second+st[y][j].second+w[x]+w[y]+dis[st[x][i].first][st[y][j].first]);
			}
		}
		qwrite(ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	c=qread();
	solve();
	return 0;
}

