#include<bits/stdc++.h>
using namespace std;
struct info{
	long long tim;
	bool f=false;
};
int c,n,d;
long long m,q;
long long w[200555];
info pas[200555][505];
bool tf[200555];
long long dfs(int now,int end,int nowlin){	
    long long minn=1e18;
    if(now==end) return 0;
    for(int j=0;j<n;j++){
		if(pas[now][j].f==true&&pas[end][j].f==true){
			long long summ=0;
			if(nowlin!=j){
				summ+=pas[now][nowlin].tim+pas[now][j].tim;
			}
	    	minn=min(minn,summ);
	    }
	}
	for(int j=0;j<n;j++){
	    if(pas[now][j].f==true){
	       	for(int i=0;i<m;i++){
	        	if(pas[i][j].f==true&&i!=now){
	        		long long summ=0;
	        		if(j!=nowlin){
	        			summ+=pas[now][nowlin].tim+pas[now][j].tim;
					}
					if(tf[i]==true) continue;
					else tf[i]=true;
	        		minn=min(dfs(i,end,j)+summ,minn);
	        		tf[i]=false;
				}
			}
		}
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<m;i++){
		tf[m]=false;
	} 
	for(int i=0;i<n;i++){
		int stanum;
		cin>>stanum;
		long long a1;
		long long t1;
		cin>>a1>>t1;
		pas[a1][i].f=true;
		pas[a1][i].tim=t1;
	}
	for(int t=0;t<q;t++){
		int sta,end;
		cin>>sta>>end;
		long long minn=1e18;
		long long suum=w[sta]+w[end];
		for(int j=0;j<n;j++){
		   	if(pas[sta][j].f==true){
		   	    long long ans=suum+pas[sta][j].tim+pas[end][j].tim+dfs(sta,end,j);
	    		minn=min(minn,ans);
	    	}
	   	}
	   	cout<<minn<<endl;
	}
	return 0;
}
