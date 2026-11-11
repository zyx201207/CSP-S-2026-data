#include<bits/stdc++.h>
using namespace std;
int n,k,mn;
int mp[1005][1005],mpst[1005],disss[1005],sch[1005];
int is2(){
	int ans=0;
	int xv[1005];
	for(int i=0;i<n;i++) xv[i]=mpst[i];
	for(int i=0;i<n;i++){
		if(xv[i]){
			ans++;
			if(ans>2) return 0;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int x=q.front();
				q.pop();
				xv[x]=0;
				for(int j=0;j<n;j++) if(mp[x][j]&&xv[j]) q.push(j);
			}
		}
	}
	return 1;
}
int dissss(int x){
	if(mpst[x]) return 0;
	if(disss[x]!=-1) return disss[x];
	int rst=-1;
	sch[x]=1;
	for(int i=0;i<n;i++){
		int v;
		if(mp[x][i]&&sch[i]==0){
			v=dissss(i)+1;
			if(v!=0){
				if(rst==-1) rst=v;
				if(v<rst) rst=v;
			}
		}
	}
	sch[x]=0;
	disss[x]=rst;
	return rst;
}
void dfs(int x,int s){
	if(s==0){
		if(is2()){
			for(int i=0;i<n;i++) disss[i]=-1;
			for(int i=0;i<n;i++) sch[i]=0;
			int mxv=0;
			for(int i=0;i<n;i++){
				int v=dissss(i);
				if(v>mxv) mxv=v;
			}
			if(mxv<mn) mn=mxv;
		}
		return;
	}
	mpst[x]=1;
	dfs(x+1,s-1);
	mpst[x]=0;
	if(s<n-x) dfs(x+1,s);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,v1,v2;
	cin>>c>>t;
	for(int fds=0;fds<t;fds++){
		cin>>n>>k;
		mn=0x3f3f3f3f;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) mp[i][j]=0;
		for(int i=0;i<n;i++) mpst[i]=0;
		for(int i=0;i<n-1;i++){
			cin>>v1>>v2;
			mp[v1-1][v2-1]=1;
			mp[v2-1][v1-1]=1;
		}
		dfs(0,k);
		cout<<mn<<endl;
	}
}