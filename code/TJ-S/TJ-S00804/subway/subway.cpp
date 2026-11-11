#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,ans=0x3f,aans;
int w[50099],ci[50099];
int line[600][600][2];
void search(int x,int y,int cnt){
	for(int i=0;i<n;i++){
		int nk=line[i][0][0];
		int cnt1=0;
		for(int j=1;j<=nk;j++){
			if(line[i][j][0]==x){
				cnt1++;
				cnt+=line[i][j][1];
				//cout<<cnt<<" ";
				for(int jj=1;jj<=nk;jj++){
					if(jj==j){
						continue;
					}
					if(line[i][jj][0]==y){
						cnt+=line[i][jj][1];
//						cout<<cnt<<" ";
						ans=min(ans,cnt+aans);
						cnt-=line[i][jj][1];
					}else if(line[i][jj][0]!=y&&ci[line[i][jj][0]]>1){
						int u=line[i][jj][0];
						line[i][jj][0]=-1;
						search(u,y,cnt+line[i][jj][1]);
						line[i][jj][0]=u;
					}
				} 
				cnt-=line[i][j][1];
			}
			break;
		}
		if(cnt1>=ci[x]){
			break;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		line[i][0][0]=k;
		for(int j=1;j<=k;j++){
			cin>>line[i][j][0]>>line[i][j][1];
			ci[line[i][j][0]]++;
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		aans=w[x]+w[y];
		search(x,y,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
