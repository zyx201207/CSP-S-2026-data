#include<iostream>
#include<vector>
using namespace std;
long long w[500005],mint[505][505];
inline void read(int &n){
	n=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		n=n*10+ch-'0';
		ch=getchar();
	}
}
inline void read(long long &n){
	n=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		n=n*10+ch-'0';
		ch=getchar();
	}
}
struct node{
	int id;
	long long tim;
};
vector<node> ve[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mint[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; i++)mint[i][i]=0;
	for(int i = 1; i <= m; i++)read(w[i]);
	for(int i = 1; i <= n; i++){
		int len;
		read(len);
		for(int j = 1; j <= len; j++){
			int a;
			long long t;
			read(a);
			read(t);
			for(auto it:ve[a]){
				mint[i][it.id]=mint[it.id][i]=min(mint[i][it.id],it.tim+t);
			}
			ve[a].push_back({i,t});
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i < n; i++)
			for(int j = i+1; j <= n; j++)
				mint[i][j]=mint[j][i]=min(mint[i][j],mint[i][k]+mint[k][j]);
	while(q--){
		int x,y;
		read(x);
		read(y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto ita:ve[x])
			for(auto itb:ve[y])
				ans=min(ans,mint[ita.id][itb.id]+ita.tim+itb.tim);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
