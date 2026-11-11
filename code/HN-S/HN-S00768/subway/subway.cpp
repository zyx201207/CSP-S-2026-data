#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a[500][4000],t[500][4000];
int find(int a[500][4000],int k,int aim){
	for(int i=0;i<4000;i++){
		if(a[k][i]==aim)return i;
	}return -1;
}
int dfs(int start,int xr,int end,int yr){
	if(start==end){
		return t[start][xr]+t[start][yr];
	}else{
		int startline,endline;
		int startmin=99999999,endmin=999999999;
		for(int i=0;i<n;i++){
			int qqqq=find(a,i,xr);
			int wwww=find(a,i,yr);
			if(qqqq!=-1&&t[i][qqqq]<startmin){
				startline=i;
				startmin=t[i][qqqq];
			}if(wwww!=-1&&t[i][wwww]<endmin){
				endline=i;
				endmin=t[i][wwww];
			}
		}
			return t[start][xr]+dfs(startline,xr,endline,yr);
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int xr,yr;
	for(int i=0;i<q;i++){
		cin>>xr,yr;
		int ans=0;
		ans+=w[xr]+w[yr];
		int startline,endline;
		int startmin=99999999,endmin=999999999;
		for(int i=0;i<n;i++){
			int qqqq=find(a,i,xr);
			int wwww=find(a,i,yr);
			if(qqqq!=-1&&t[i][qqqq]<startmin){
				startline=i;
				startmin=t[i][qqqq];
			}if(wwww!=-1&&t[i][wwww]<endmin){
				endline=i;
				endmin=t[i][wwww];
			}
		}
		cout<<ans+dfs(startline,xr,endline,yr);
	}
	return 0;
} 
