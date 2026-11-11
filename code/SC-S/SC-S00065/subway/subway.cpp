#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20010],k[510],a[510][20010],t[510][20010],x,y,mins,sum;
bool b[20010][510],vis[20010];
bool xl(int ditie,int chezhan){
	for(int i=1;i<=k[ditie];i++){
		if(a[ditie][i]==chezhan){
			sum=i;
			return 1;
		}
	}
	return 0;
}
void dfs(int s,int co,int f){
	//cout<<"dfs("<<s<<","<<co<<","<<f<<")\n";
	if(f==y){
		co-=t[s][f];
		//cout<<"[+]ans="<<co<<" 经过";
//		for(int i=1;i<=m;i++){
//			if(vis[i])cout<<"站台"<<i<<" ";
//		}
		cout<<endl;
		mins=min(mins,co);
		return;
	}
	for(int i=1;i<=k[s];i++){ 
		int l=a[s][i];//车站
		if(vis[l])continue;
		for(int j=1;j<=n;j++){//地铁 
			if(j==s)continue;
			if(xl(j,l)){
				vis[l]=1;
				//cout<<"t[j][l]="<<t[j][l]<<" t[s][l]="<<t[s][l]<<endl;
				dfs(j,co+t[j][sum]+t[s][sum],l);
				vis[l]=0;
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	//memset(me,0x3f3f3f,sizeof(me));
	cin>>c>>n>>m>>d>>q;
	if(c>=20){
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//cout<<"输入完毕\n";
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j]; 
			//b[a[i][j]][i]=1;
		}
	}
	//cout<<"输入完毕\n";
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		mins=INT_MAX;
		for(int j=1;j<=n;j++){
			if(xl(j,x)){
				vis[x]=1;
				dfs(j,t[j][x],x);
				vis[x]=0;
			}
		}
		cout<<w[x]+w[y]+mins<<endl;
	}
	return 0;
}
/*
0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/