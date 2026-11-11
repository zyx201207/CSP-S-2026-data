#include<bits/stdc++.h>
using namespace std;


int c,n,m,d,q;

int w[500005];
int t[505][500005];
struct edge{
	int index,to;
};
vector<edge> ma[50005];

struct node{
	int x,t,ni;
	bool vis[500005];
	/*
	operator<(const node& a) const
    {
		return t>a.t;
    }
    
    operator=(const node a)
    {
		*this=a;
    }*/
};
int ans;

//Not void
//Not include enter and exit's time
int search(int start,int end){
	
	ans=INT_MAX;
	
	node st;
	st.x=start,st.t=0,st.ni=-1;
	memset(st.vis,0,sizeof st.vis);
	st.vis[start]=1;
	
	//priority_queue<node,vector<node>,less<node> > q;
	queue<node> q;
	q.push(st);
	
	//cout<<q.size();
	
	while(!q.empty()){
		node now=q.front();
		q.pop();
		
		
		if(now.t>=ans){
			continue;
		}
		
		//cout<<"now at"<<now.x<<" Time:"<<now.t<<" At line"<<now.ni<<endl;
	
		if(now.x==end){
			//cout<<now.t+t[now.ni][end]<<endl;
			ans=min(ans,(now.t+t[now.ni][end]));
		}else{
			
			for(int i=0;i<ma[now.x].size();i++){
				if(now.vis[ma[now.x][i].to]==0){
					node tmp=now;
					tmp.t=0;tmp.ni=0;tmp.x=0;
					
					
					tmp.vis[ma[now.x][i].to]=1;
					//cout<<now.x<<"can go to"<<ma[now.x][i].to<<endl;
					
					if(ma[now.x][i].index!=now.ni){ //transfer
						//cout<<now.x<<"to"<<ma[now.x][i].to<<"need transfer. Now At line"<<now.ni<<endl;
						tmp.t=now.t;
						if(now.ni==-1){
							//cout<<now.ni<<" "<<now.x<<" "<<ma[now.x][i].index<<endl;
							tmp.t=tmp.t+t[ma[now.x][i].index][now.x];
							
						}else{
							//cout<<now.ni<<" "<<now.x<<" "<<ma[now.x][i].index<<endl;
							tmp.t=tmp.t+t[now.ni][now.x]+t[ma[now.x][i].index][now.x];
						}
						tmp.ni=ma[now.x][i].index;
						
					}else{
						tmp.t=now.t;
						tmp.ni=now.ni;
						
					}
					
					tmp.x=ma[now.x][i].to;
					
					q.push(tmp);
					
					
					
				}
			}
			
		}
		
		
	}
	
	return ans;

	
	
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/

int main(){
	
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int tmp;
		for(int j=1;j<=k;j++){
			int a,tt;
			cin>>a>>tt;
			
			t[i][a]=tt;
			
			if(j>1){
				int from=a,to=tmp;
				edge tmp;
				tmp.index=i;
				tmp.to=to;
				ma[from].push_back(tmp);
				tmp.to=from;
				ma[to].push_back(tmp);
			}
			tmp=a;
		}
	}
	
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<search(x,y)+w[x]+w[y]<<endl;
	}
	
	
	
	return 0;
}
