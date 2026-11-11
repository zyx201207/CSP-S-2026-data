//#include<bits/stdc++.h>
//using namespace std;
//int m,n;
//int w[5005];
//int c;
//int k[5005];
//int d;
//int q;
//int a[1000][1000];
//int t[1000][1000];
//int start[5005],last[5005];
//bool isA=1;
//int visit[5005];
//int he;
//int ans;
//void dfs(int y,int tas,int startt){
//	visit[y]=1;
//	if(y==tas){
//		he+=w[y]+w[startt]+t[n][n];
//		ans=min(ans,he);
//		return;
//	}
//	for(int i=0;i<k[i];i++){
//		if(visit[a[n][i]]==0){
//			he+=t[n][n];
//			dfs(a[n][i],tas,startt);
//		}
//	}
//}
//int main(){
//	cin>>c>>n>>m>>d>>q;
//	for(int i=0;i<m;i++){
//		cin>>w[i];
//	}
//	for(int i=0;i<n;i++){
//		cin>>k[i];
//		if(k[i]>2){
//			isA=false;
//		}
//		for(int j=0;j<k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//		}
//	}
//	for(int i=0;i<q;i++){
//		cin>>start[i]>>last[i];
//	}
////	if(isA){
//		for(int i=0;i<q;i++){
////			he=start[i];
//			memset(visit,0,sizeof(visit));
//			he=0;
//			ans=0x3f3f3f3f;
//			dfs(start[i],last[i],start[i]);
//			cout<<ans<<endl;
//		} 
////	}
//	return 0;
//}
////0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
#include<bits/stdc++.h>
using namespace std;
int m,n;
int w[5005];
int c;
int k[5005];
int d;
int q;
int a[1000][1000];
int t[1000][1000];
int start[5005],last[5005];
bool isA=1;
int visit[5005];
int he;
int ans;
//void dfs(int y,int tas,int startt){
//	visit[y]=1;
//	if(y==tas){
//		he+=w[y]+w[startt]+t[startt][startt];
//		ans=min(ans,he);
//		return;
//	}
//	for(int i=0;i<k[i];i++){
//		if(visit[i]==0){
//			he+=t[y][i];
//			dfs(i,tas,startt);
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		if(k[i]>2){
			isA=false;
		}
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>start[i]>>last[i];
	}
	for(int i=0;i<q;i++){
		cout<<w[start[i]]+t[start[i]][start[i]]+t[start[i]][last[i]]+t[last[i]][last[i]]+w[last[i]]<<endl;
	}
//	if(isA){
//		for(int i=0;i<q;i++){
////			he=start[i];
//			memset(visit,0,sizeof(visit));
//			he=0;
//			ans=0x3f3f3f3f;
//			dfs(start[i],last[i],start[i]);
//			cout<<ans<<endl;
//		} 
//	}
	return 0;
}
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2

