#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int M=2e4+10;
const int Q=1e5+10;
int c,n,m,d,q,w[N],t[N][M][M],ans;
queue<int>a[N];
int sum;

void bfs(int x,int y){
	if(x==y)return;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[i][x][j]!=0){
				sum+=t[i][x][j];
				bfs(j,y);
				sum-=t[i][x][j];
			}
		}
	}
}

int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			t[i][ai][0]=ti;
			a[i].push(ai);
		}
	}
	for(int i=1;i<=n;i++){
		int c[M];
		for(int j=1;j<=a[i].size();j++){
			c[j]=a[i].front();
			a[i].push(a[i].front());
			a[i].pop();
		}
		for(int j=1;j<=a[i].size();j++){
			for(int g=1;g<=a[i].size();g++){
				if(c[j]==c[g])continue;
				t[i][c[j]][c[g]]=t[i][c[j]][0];
				t[i][c[g]][c[j]]=t[i][c[g]][0];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0;
		ans+=w[x]+w[y];
		sum=0;
		bfs(x,y);
		cout<<sum+ans<<"\n";
	}
	
	return 0;
}
/*
AKIOI
Oct31==Dec25?
*/
