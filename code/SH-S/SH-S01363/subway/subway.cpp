#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int M[500];//从每个地铁站的地铁口走到站厅需要的时间。
int K[500],A[500][5000],T[500][5000];//第 i 条线路经过的地铁站数,     表示第 i 条线路经过的第 j 个地铁站，     表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int R[500][2];//第 r 个出行计划的起点和终点所在的地铁站编号。
stack<int> a[500]; //第i个地铁站经过的第j个线路 
int a1[500][500];//地铁站编号为i的地铁，在第j号路线中是第几个 
int ans=100086;
void dfs(int st,int en,int sum,bool tie,int xian){//st:出发点   en：终点      sum:花费总时间    
	
	if(tie==true){
		sum+=T[xian][a1[st][xian]];
	}
	if(st==en){
		ans=min(ans,sum);
		return;
	}
	stack<int> q=a[st];
	while(!q.empty()){
		int i=q.top();
		q.pop();
		if(i==st){
			break;
		}
		sum+=T[i][a1[st][i]];
		for(int j=0;j<K[i];j++){
			dfs(A[i][j],en,sum,true,i);
		} 
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>M[i];
	}
	for(int i=0;i<n;i++){
		cin>>K[i];
		for(int j=0;j<K[i];j++){
			cin>>A[i][j]>>T[i][j];
			a[T[i][j]].push(i);
			a1[T[i][j]][i]=j; 
		}
	}
	for(int i=0;i<q;i++){
		cin>>R[i][0]>>R[i][1];
		dfs(R[i][0],R[i][i],0,false,0);
		cout<<M[R[i][0]]+M[R[i][0]]+ans<<endl;
		ans=100086;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
