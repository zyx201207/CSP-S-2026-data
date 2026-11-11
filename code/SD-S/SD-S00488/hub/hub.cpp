#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[1001][1001];
long long ans,vv;
vector<int>h[1001];
void sw(int x,int fa,int w){
	if(f[x][fa]){
		return;
	}
	f[x][fa]=f[fa][x]=w;
	for(int i=0;i<h[x].size();i++){
		if(!f[x][fa]){
			sw(h[x][i],fa,w+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof f);
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			h[x].push_back(y);
			h[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<h[i].size();j++){
				sw(h[i][j],i,1);
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
			    vv=0;
			    for(int j=1;j<=n;j++){
				    vv+=f[i][j];
			    }
			    ans=max(ans,vv);
		    }
		}
		if(k==2){
			for(int a1=1;a1<=n;a1++){
			for(int i=1;i<=n;i++){
			    vv=0;
			    for(int j=1;j<=n;j++){
				    vv+=min(f[i][j],f[a1][j]);
			    }
			    ans=max(ans,vv);
		    }
		}
		}
		if(k==3){
			for(int a1=1;a1<=n;a1++){
			for(int a2=1;a2<=n;a2++){
			for(int i=1;i<=n;i++){
			    vv=0;
			    for(int j=1;j<=n;j++){
				    vv+=min(f[i][j],min(f[a1][j],f[a2][j]));
			    }
			    ans=max(ans,vv);
		    }
		    }
		}
	    }
		if(k==4){
			for(int a1=1;a1<=n;a1++){
			for(int a2=1;a2<=n;a2++){
			for(int a3=1;a3<=n;a3++){
			for(int i=1;i<=n;i++){
			    vv=0;
			    for(int j=1;j<=n;j++){
				    vv+=min(f[i][j],min(f[a1][j],min(f[a2][j],f[a3][j])));
			    }
			    ans=max(ans,vv);
		    }
		}
	    }
		}
	    }
		if(k==5){
			for(int a1=1;a1<=n;a1++){
			for(int a2=1;a2<=n;a2++){
			for(int a3=1;a3<=n;a3++){
			for(int a4=1;a4<=n;a4++){
			for(int i=1;i<=n;i++){
			    vv=0;
			    for(int j=1;j<=n;j++){
				    vv+=min(f[i][j],min(f[a1][j],min(f[a2][j],min(f[a3][j],f[a4][j]))));
			    }
			    ans=max(ans,vv);
		    }
		}
	    }
        }
        }
		printf("%d\n",ans);
	    }
	}
	return 0;
}
