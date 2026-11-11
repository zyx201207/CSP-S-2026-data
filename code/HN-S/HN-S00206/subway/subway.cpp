#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long minn=1e9+9;
long long ans=0,w[N],o[N]={0},t[N][N];
bool l[N]={false};
queue<int> m[N];
struct A{
	int st,ti;
}a[N][N];

int find(int x,int y){
	for(int i=1;i<=o[x];i++){
		for(int j=1;j<=o[y];j++){
			if(t[x][i]==t[y][j]){
				return i;
			}
		}
	}
}
void A(int x1,int y1){
	m[x1].push(y1);
	m[y1].push(x1);
}
void DFS(int x,int y){
	if(x==y){
		minn=min(minn,ans);
		return ;
	}
	for(int i=1;i<=m[x].size();i++){
		int p=m[x].front();
		//cout<<p<<" "<<endl;
		if(l[p]==false){
			l[p]=true;
			ans+=a[find(x,p)][i].ti;
			//cout<<ans<<endl;
			m[x].pop();
			DFS(p,y);
			l[p]=false;
			ans-=a[find(x,p)][i].st;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].st>>a[i][j].ti;
			t[a[i][j].st][o[a[i][j].st]++]=i;
			if(j!=1){
				int a1=a[i][j].st;
				int a2=a[i][j-1].st;
				A(a1,a2);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		DFS(x,y);
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
