#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1e3;
int c,n,m,d,p,x,y;
int w[N],u[N][N],a[N],t[N],tim[N][N];
int b[N];
int minn=INT_MAX;
void f(int x1,int y1,int cs){

	if(x1==y1){
		minn=min(cs,minn);
	}
	
	for(int i=1;i<=u[x1][0];i++){
		if(b[u[x1][i]]==0){
			if(cs+tim[x1][u[x1][i]]<minn){
				b[u[x1][i]]=1;
				f(u[x1][i],y1,cs+tim[x1][u[x1][i]]);
				b[u[x1][i]]=0;
			}	
		}
		
	}
	return ;
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=1;j<=c;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=c;j++){
			for(int k=1;k<=c;k++){
				if(j!=k){
					u[a[j]][++u[a[j]][0]]=a[k];
					tim[a[j]][a[k]]=t[j]+t[k];
				}
			}
		}
	}	
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		minn=INT_MAX;
		b[x]=1;
		f(x,y,0);
		b[x]=0;
		cout<<minn+w[x]+w[y]<<" ";
	}
	return 0;
}