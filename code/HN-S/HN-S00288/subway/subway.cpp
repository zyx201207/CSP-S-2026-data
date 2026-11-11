#include<bits/stdc++.h>
using namespace std;
int va[100001],fl[700][700],pic[100001][20],w[100001][20],top[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,t,u,v,ans,x,y;
	cin>>c>>n>>m>>d>>q;
	//memset(fl,-1,sizeof(fl));
	for(int i=0;i<m;i++){
		cin>>va[i];
	}
	for(int i=0;i<n;i++){
		cin>>t;
		for(int j=0;j<t;j++){
			cin>>u>>v;u--;
			w[u][top[u]]=v;
			pic[u][top[u]++]=i;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<top[i];j++){
			for(int k=0;k<top[i];k++){
				if(pic[i][j]!=pic[i][k]&&(fl[pic[i][j]][pic[i][k]]==0||w[i][k]+w[i][j]<fl[pic[i][j]][pic[i][k]])){
					fl[pic[i][j]][pic[i][k]]=w[i][k]+w[i][j];
					fl[pic[i][k]][pic[i][j]]=w[i][k]+w[i][j];
				}
			}
		}
	}/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<fl[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				if((fl[i][k]!=0&&fl[j][k]!=0)&& (fl[i][j]==0||fl[i][j]>fl[i][k]+fl[j][k])){
					fl[i][j]=fl[i][k]+fl[j][k];
				}//cout<<"OK";
			}
		}
	}
	for(int i=0;i<q;i++){
		ans=0;
		cin>>x>>y;x--;y--;
		for(int j=0;j<top[x];j++){
			for(int k=0;k<top[y];k++){
				if(pic[x][j]==pic[y][k]){
					ans=w[x][j]+w[y][k];
					continue;
				}
				if(fl[pic[x][j]][pic[y][k]]!=0&&(ans==0||(ans>w[x][j]+w[y][k]+fl[pic[x][j]][pic[y][k]])))
					ans=w[x][j]+w[y][k]+fl[pic[x][j]][pic[y][k]];
			}
		}
		cout<<ans+va[x]+va[y]<<endl;
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<top[i];j++){
			cout<<i<<"->"<<pic[i][j]<<" "<<w[i][j]<<endl;
		}
	}*/
	
}

