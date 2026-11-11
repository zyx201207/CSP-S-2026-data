#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
struct node{
	int pp,spend;
};
int spend=0;
int w[maxn];
int k[501];
int a[maxn][500];
long long t[500];
int c,n,m,d,q;
int start,end;
queue<int>o;
bool vis[500];
void bfs(int x){
	o.push(x);
	spend+=w[x]; 
	cout<<o.front()<<' ';
	if(x==end){
		return;
	}
	while(!o.empty()){
		
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			
			bool y=false;
			for(int j=1;j<=k[i];j++){
				if(o.front()==a[i][j]){
					y=true;
					vis[i]=1;
				}
			}
		/*		
		*/
			if(y){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==o.front())continue;
					int f=a[i][j];
					o.push(f);
					cout<<a[i][j]<<' ';
					if(a[i][j]==end){
						
						cout<<a[i][j];
						break;
					}
						
					//cout<<a[i][l]<<' ';
				}
				
			}
			
			
				
		
		}
		o.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k1;cin>>k1;
		k[i]=k1;
		for(int j=1;j<=k1;j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i][j]=a1;
			t[j]=t1;
		}
	}
			for(int z=1;z<=n;z++){
				for(int b=1;b<=k[z];b++){
					cout<<a[z][b]<<' ';
				}
				cout<<endl;
			}
	//for(int i=1;i<=q;i++){
	
		memset(vis,0,sizeof(vis));		
		cin>>start>>end;
		bfs(start);
//	}

	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
