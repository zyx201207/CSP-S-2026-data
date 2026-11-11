#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int zt[500005],mp[500005]={};
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zt[i];
	}vector<int>g[500005],v[500005],g2[500005],v2[500005];
	int zd,tm;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>zd>>tm;
			g[zd].push_back(i);
			g2[i].push_back(zd);
	        v[zd].push_back(tm);
	        v2[i].push_back(tm);
	        mp[zd]++;
		}
		
	}
	int zq,zz;
	queue<int>h,b,o;
	for(int i=1;i<=q;i++){
		cin>>zq>>zz;
		int minnx=1e9;
		int vis[500005][500005],vis2[500005][500005];
		h.push(zq);
		b.push(zt[zq]);
		o.push(0);
		int wz=0;
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		while(!h.empty()){
			int f=h.front();h.pop();
			int r=b.front();b.pop();
			int op=o.front();o.pop();
			if(f==zz) minnx=min(minnx,r);
			if(wz==0){
			    for(int j=0;j<g[f].size();j++){
			    	if(vis[g[f][j]][f]==0&&vis[f][g[f][j]]==0){
			    		for(int p=0;p<g2[g[f][j]].size();p++){
		    	        	if(vis2[g2[g[f][j]][p]][g[f][j]]==0&&vis2[g[f][j]][g2[g[f][j]][p]]==0){
			   	            	h.push(g2[g[f][j]][p]);
			   	            	b.push(r+v[f][j]+v2[g[f][j]][p]);
			   	            	vis[f][g[f][j]]=1;
			               		vis2[g2[g[f][j]][p]][g[f][j]]=1;
			               		o.push(g[f][j]);
			   	            }
				        }
			   	    }
			    }
			    wz=1;
		    }
		    else{
		    	if(mp[f]>1){
		    		for(int j=0;j<g[f].size();j++){
		    			if(vis[g[f][j]][f]==0&&vis[f][g[f][j]]==0){
		    				if(g[f][j]!=op) r+=v[f][j];
		    		    	for(int p=0;p<g2[g[f][j]].size();p++){
		    		    		if(vis2[g2[g[f][j]][p]][g[f][j]]==0&&vis2[g[f][j]][g2[g[f][j]][p]]==0){
		    		    			h.push(g2[g[f][j]][p]);
			   	             	    b.push(r+v2[g[f][j]][p]);
			   	                	vis[f][g[f][j]]=1;
			               	    	vis2[g2[g[f][j]][p]][g[f][j]]=1;
			               	    	o.push(g[f][j]);
		    		    		}
		    		    	}
		    	    	}
		    		}
				}
		    	else{
		        	for(int p=0;p<g2[op].size();p++){
		    	    	if(vis2[op][p]==0&&vis2[p][op]==0){
		    		    	h.push(g2[op][p]);
			   	            b.push(r+v2[op][p]);
			               	vis2[g2[op][p]][op]=1;
			               	o.push(op);
			            }
			    	}
				}
			}
		}
		cout<<minnx<<endl;
	}
	return 0;
}

