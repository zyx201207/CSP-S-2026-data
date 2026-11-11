#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][505];
int t[505][505];
int v[505]; 
int xx;
int yy; 
int res=1000000009;
int tot=0;
void dfs(int zhan,int goal,int ti){
	tot++;
	if(zhan==goal){
		//for(int i=1;i<=tot;++i) cout<<"  ";
		//cout<<"枚举结果时间为"<<ti<<endl; 
		res=min(res,ti);
		tot--;
	    return;
	}//如果当前站就是终点，返回 
	for(int i=1;i<=n;++i){//枚举每一条铁路
	    //for(int ii=1;ii<=tot;++ii) cout<<"  ";
		//cout<<zhan<<"出发，验证铁路"<<i<<endl; 
		int flag=0;//看看能否到达这个站点 
		int cmt=0;
		for(int j=1;j<=k[i];++j){
			if(a[i][j]==zhan){
				//for(int ii=1;ii<=tot;++ii) cout<<"  ";
	        	//cout<<"可以到达"<<endl; 
				flag=1;//可以到达，标记 
				cmt=t[i][j];
				break;
			}
		}
		if(flag==1){//如果可以到达，就枚举路线 
		    for(int j=1;j<=k[i];++j){
		    	if(a[i][j]!=zhan&&v[a[i][j]]==0){
		    		//for(int ii=1;ii<=tot;++ii) cout<<"  ";
		    		//cout<<"从当前站点移动到站台需要"<<cmt<<endl;
		    		//for(int ii=1;ii<=tot;++ii) cout<<"  ";
	            	//cout<<"从铁路"<<i<<"由站点"<<zhan<<"移动至站点"<<a[i][j]<<endl; 
	            	//for(int ii=1;ii<=tot;++ii) cout<<"  ";
	            	//cout<<"此时所需要的花费"<<cmt<<" "<<t[i][j]<<endl;
		    		v[a[i][j]]=1;
		    	    dfs(a[i][j],goal,ti+cmt+t[i][j]);
		    	    v[a[i][j]]=0;
		    	}
			}
		}
	}
	tot--;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试编号，地铁路线，地铁站数，最多路线，计划数
	for(int i=1;i<=m;++i){
		cin>>w[i];//输入每一个站点进出需要的时间 
	} 
	for(int i=1;i<=n;++i){
		cin>>k[i];//输入每一条铁路至多需要可以到达多少个站点 
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];//输入站点和所需时间 
		}
	}
	for(int i=1;i<=q;++i){
		cin>>xx>>yy;//输入出发点和终点 
		res=1000000009;//初始化res 
		v[xx]=1;
		dfs(xx,yy,0);//深搜 
		v[xx]=0;
		cout<<res+w[xx]+w[yy]<<endl;
	}
}