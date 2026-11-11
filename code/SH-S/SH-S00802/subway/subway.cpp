#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long ccc,n,m,d,q;
long long ww[500005];
long long a[505][20005];
long long t[505][20005];
long long k[505];
bool in[505][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			in[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		queue<int>q;
		q.push(u);
		int vst[20005]={0};
		vst[u]=1;
		while(q.size()){
			int r=q.front();
			q.pop();
			if(r==v){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(in[j][r]){
					for(int c=1;c<=k[j];c++){
						if(a[j][c]==r){
							continue;
						}
						if(vst[a[j][c]]==0||vst[a[j][c]]>vst[r]+in[j][r]+in[j][a[j][c]]){
							vst[a[j][c]]=vst[r]+in[j][r]+in[j][a[j][c]];
							q.push(a[j][c]);
						}
					}
				}
			}
		}
		cout<<vst[v]+ww[u]+ww[v]-1<<endl;
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
