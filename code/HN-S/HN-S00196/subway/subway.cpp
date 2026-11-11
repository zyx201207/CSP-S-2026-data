#include<bits/stdc++.h>
using namespace std;
struct j{
	int to;
	int xl; 
};    
struct jj{
	int at;
	int xl;
	int ans;
}; 
int c,n,m,d,q,ans=0;
vector<int> w,k,x,y;
vector<vector<int> > a,t;
vector<vector<j> > xl;     
queue<jj> www;
int bfs(int start,int end){
	int minn=-1;
	for (int i=0;i<xl[start].size();i++){
		www.push({xl[start][i].to,xl[start][i].xl,t[xl[start][i].xl][start]});
	//	cout<<"开始搜索的路程"<<t[xl[start][i].xl][start]<<" \n";
	}
	while (!www.empty()){
		jj at=www.front();
		www.pop();
		if (at.at==end){
		//	cout<<"当前ans"<<at.ans<<" \n";
			at.ans+=t[at.xl][at.at];
		//	cout<<"结尾返回"<<t[at.xl][at.at]<<" 线路:"<<at.xl<<" 哪个"<<at.at<<" \n";
			if (minn==-1) minn=at.ans;
			else minn=min(minn,at.ans);
		//	cout<<"当前最小"<<minn<<" \n";
		}else{
			for (int i=0;i<xl[at.at].size();i++){
				if (at.xl!=xl[at.at][i].xl){
					at.ans+=t[at.xl][at.at]+t[xl[at.at][i].xl][at.at];
					//cout<<"变线路"<<t[at.xl][at.at]+t[xl[at.at][i].xl][at.at]<<" \n";
				}
				www.push({xl[at.at][i].to,xl[at.at][i].xl,at.ans});
				//cout<<"当前ans"<<at.ans<<" \n";
			}
		}
	}
	return minn;
}                                                                                          
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	w=vector<int> (m+1,0);
	k=vector<int> (n+1,0);
	x=vector<int> (q+1,0);
	y=vector<int> (q+1,0);
	a=vector<vector<int> > (n+1,vector<int> ());
	t=vector<vector<int> > (n+1,vector<int> (m+1,0));
	xl=vector<vector<j> > (m+1,vector<j> ());
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		a[i]=vector<int> (k[i],0);
		for (int j=1;j<=k[i];j++){
			int temp;
			cin>>a[i][j]>>temp;
			t[i][a[i][j]]=temp;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<k[i];j++){
			xl[a[i][j]].push_back({a[i][j+1],i});
			xl[a[i][j+1]].push_back({a[i][j],i});
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for (int i=1;i<=q;i++){
		ans=w[x[i]]+w[y[i]];
		ans+=bfs(x[i],y[i]);
		cout<<ans<<'\n';
	}
	return 0;
}

