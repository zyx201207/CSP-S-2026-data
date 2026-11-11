#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[1000],kk[1000][1000],dis[1000];
void sub_1(){
	
	for(int i=0;i<=m+10;i++){
		for(int j=0;j<=m+10;j++){
			kk[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,aa[1000],dd[1000];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa[j]>>dd[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				kk[aa[j]][aa[l]]=kk[aa[l]][aa[j]]=min(dd[j]+dd[l],kk[aa[l]][aa[j]]);
			}
		}
	}
	for(int i=0;i<=m+10;i++){
		kk[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			//cout<<kk[i][j]<<' '<<i<<' '<<j<<endl;
			for(int k=1;k<=m;k++){
				kk[i][j]=kk[j][i]=min(kk[i][k]+kk[k][j],kk[j][i]);
			}
			//cout<<kk[i][j]<<' '<<i<<' '<<j<<endl;
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<min(kk[x][y],kk[y][x])+w[x]+w[y]<<endl;
		//cout<<min(kk[x][y],kk[y][x])<<endl;
	}
	return;
}



















void sub_2(){
	
	
	for(int i=0;i<=m+10;i++){
		for(int j=0;j<=m+10;j++){
			kk[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a1,a2,d1,d2;
		cin>>k;
		cin>>a1>>d1>>a2>>d2;
		kk[a1][a2]=kk[a2][a1]=min(d1+d2,kk[a1][a2]);
	}
	for(int i=0;i<=m+10;i++){
		kk[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			//cout<<kk[i][j]<<' '<<i<<' '<<j<<endl;
			for(int k=1;k<=m;k++){
				kk[i][j]=kk[j][i]=min(kk[i][k]+kk[k][j],kk[j][i]);
			}
			//cout<<kk[i][j]<<' '<<i<<' '<<j<<endl;
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<min(kk[x][y],kk[y][x])+w[x]+w[y]<<endl;
		//cout<<min(kk[x][y],kk[y][x])<<endl;
	}
	return;
}









void dfs(int u,int st){
	if(dis[st]<=u) return ;
	dis[st]=u;
	for(int i=1;i<=m;i++){
		if(kk[i][st]) dfs(u+1,i);
	}
	return;
}

void sub_3(){
	int di;
	
	for(int i=0;i<=m+10;i++){
		for(int j=0;j<=m+10;j++){
			kk[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,aa[1000],dd[1000];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa[j]>>dd[j];
			di=dd[j];
			cout<<aa[j]<<"--"<<dd[j]<<endl;
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				kk[aa[j]][aa[l]]=kk[aa[l]][aa[j]]=min((int)1,kk[aa[l]][aa[j]]);
			}
		}
	}
	for(int i=0;i<=m+10;i++){
		kk[i][i]=0;
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;dfs(x,0);
		cout<<di<<' '<<dis[y]<<w[x]+w[y]<<endl;
		cout<<di*dis[y]+w[x]+w[y]<<endl;
	}
	return ;
}





signed main(){
	freopen("subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11) sub_1();
	else sub_3();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 2 3 2 1
2 2 2
2 1 2 2 2
2 2 2 3 2
*/
