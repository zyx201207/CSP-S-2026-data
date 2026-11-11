#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N=1e5+5;

int w[N],k[405],a[3][405],b[3][405],t[20][405];
int ans=1e6;
int hunt(int g,int s){
	for(int i=1;i<=k[g];i++){
		if(a[g][i]==s){
			return i;	
		}
	}	
	return 0;	
}
int vis[405];
void dfs(int g,int s,int x,int y,int z){
	if(x==y&&z+t[g][a[g][s]]<ans){
		ans=z+t[g][a[g][s]];
		//cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=2;i++){
		if(b[i][x]==1){
			vis[x]=1;
			if(g==i&&vis[a[i][s+1]]==0){
				dfs(i,s+1,a[i][s+1],y,z+t[i][a[i][x]]);
			}else if(g!=i&&vis[hunt(1,x)+1]==0){
				dfs(i,hunt(1,x)+1,a[i][hunt(1,x)+1],y,z+t[i][a[i][x]]);	
			}
		}	
	}
}
int main(){
	//0 3 7 20 2
    //8 3 6 1 7 2 9
    //3 1 4 2 5 5 100
    //3 2 6 3 1 7 2
    //4 3 2 5 100 4 6 6 7
    //1 6
    //2 3
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
	    cin>>k[i];
	    int v=0;
	    for(int j=1;j<=2*k[i];j++){
	    	if(j%2==1){
	    		int n;
	    		cin>>n;
	    		v=n;
	    		a[i][1+j/2]=n;
	    		b[i][n]=1;
			}else if(j%2==0){
				cin>>t[i][v];
			}
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		int x,y;
		cin>>x>>y;	
		int a1=0;
		for(int i=1;i<=2;i++){
			if(b[1][x]==1){
				for(int j=1;j<=k[i];j++){
				    if(a[i][j]==x){
					    dfs(1,j,x,y,w[x]+w[y]);
				    }
			    }
			}	
			if(b[2][x]==1){
				for(int j=1;j<=k[i];j++){
				    if(a[i][j]==x){
					    dfs(2,j,x,y,w[x]+w[y]);
				    }
			    }
			}	
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}