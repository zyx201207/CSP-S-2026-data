#include<iostream>
#include<vector>
#define  int  long long
using namespace std;
constexpr int N=5e5+5;
bool Beg;

int n,m,a[N],lst[N];
int sm[N],d[N];
struct Node{
	int L,R;
}b[N];
vector<int> v[N];

int dfs(int x){
	int c=1;
	for(int u:v[x])c+=dfs(u);
	sm[b[x].L]+=c;
	sm[b[x].R+1]-=c;
	return c;
}
bool End;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[n+1]=Node{n+1,n};
	for(int i=n,L=n;i;i--){
		if(lst[a[i]])L=i;
		else lst[a[i]]=i;
		b[i]=Node{i,L};
		v[lst[a[L]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=n;i++)
		sm[i]+=sm[i-1],
		d[a[i]]+=sm[i];
	for(int i=1;i<=m;i++)
		cout<<d[i]<<' ';
	cout<<'\n';
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
