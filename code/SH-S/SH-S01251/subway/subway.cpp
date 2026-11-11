#include<bits/stdc++.h>
using namespace std;
long long cnt[509],w[1009],visit[1009][1009];
struct node{
	long long num;
	long long val; 
}f[509][1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			cin>>f[i][j].num>>f[i][j].val;
		}
	}
	for(int i=0;i<=1008;i++){
		for(int j=0;j<=1008;j++){
			visit[i][j]=10000009;
		}
	}
	for(int i=0;i<=1008;i++) visit[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				if(j==k) continue;
				visit[f[i][k].num][f[i][j].num]=visit[f[i][j].num][f[i][k].num]=min(visit[f[i][j].num][f[i][k].num],f[i][j].val+f[i][k].val);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i==k||j==k) continue;
				visit[j][i]=visit[i][j]=min(visit[i][j],visit[i][k]+visit[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<visit[a][b]+w[a]+w[b]<<endl;
	}
	return 0;
} 
