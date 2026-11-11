#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sta[500005];
int line[505][500005],ks[505],x[100005],y[100005];
bool vis[500005];

int find_line(int p,int l){
	if(l==-1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=ks[i];++j){
				if(line[i][j]==p) return i; 
			}
		}
	}else{
		for(int j=1;j<=ks[l];++j){
			if(line[l][j]==p) return j; 
		}return -1;
	}
	
}

int bfs(int s1,int s2,int t){
	queue<int> p;
	queue<int> t2;
	p.push(s1);t2.push(t);
	while(p.size()!=0){
		int np=p.front();int nt=t2.front();
		p.pop();t2.pop();
		for(int i=1;i<=n;++i){
			if(find_line(np,i)!=-1){
				for(int j=1;j<=ks[i];++j){
					if(!vis[j]){
						p.push(j);
						t2.push(nt+line[i][np]+line[i][j]);
					}
				}
			}
		}
	}
}

int main(){
//	freopen("subway.in" ,"r",stdin );
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>sta[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;ks[i]=k;
		for(int j=1;j<=2*k;++j){
			cin>>line[i][j];
		}
	}for(int i=1;i<=q;++i) cin>>x[i]>>y[i];
	for(int w=1;w<=q;++w){
		int t=0;
		t+=sta[x[w]]+sta[y[w]];
		bfs(x[w],y[w],t);
		cout<<t<<'\n';
	}
	return 0;
}
