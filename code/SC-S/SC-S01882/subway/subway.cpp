#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;int subway[10005][10005];
bool ctfind(int way[],int i,int temp){
	for(int j=0;j<temp;++j){
		if(way[j]==i) return 0;
	}
	return 1;
}
int dfs(int s,int e,int way[],int temp,vector<int> w,vector<int> t){
	way[temp]=s; ++temp;
	if(s==e){
		int t1;
		for(int i=0;i<temp;++i){
//			cout<<way[i]<<" ";
			if(i==0 || i==temp-1){
				t1+=w[way[i]];cout<<w[way[i]]<<" ";
				t1+=t[way[i]];cout<<t[way[i]]<<" ";
			}
			else{
				t1+=t[way[i]]*2;cout<<t[way[i]]*2<<" ";
			}
		}
		return t1;
	}
	for(int i=1;i<=m;++i){
		if(subway[s][i] == 1 && ctfind(way,i,temp)){
			cout<<s<<" "<<i<<endl;
			return dfs(i,e,way,temp,w,t);
		}
	}
//	return 0;	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	vector<int> t(m);
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=0;i<n;++i){
		int k;cin>>k;
		int u,t1,u1;cin>>u>>t1;//Ut 启动
		t[u]=t1;
		for(int i=1;i<k;++i){
			cin>>u1>>t1;	
			t[u1]=t1;
			subway[u][u1]=1; 
			subway[u1][u]=1;
			u=u1;
		}
	}
	//哦nonono我无疑是难绷的求不要TLE不要WA
	while(q--){
		int s,e,temp=0;cin>>s>>e;
		int way[n];
		cout<<endl<<dfs(s,e,way,0,w,t)+4<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/