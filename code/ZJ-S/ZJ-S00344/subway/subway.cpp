#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10,M=1e3+10;
int c,n,m,d,q;
int w[N],k[N],a[M][M],t[M][M],x[N],y[N];
int v[N][99];
//v[Õ¾µã±àºÅ][Â·¾¶±àºÅ]
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	} 
	
	
	
	for(int p=1;p<=q;p++){//1e5
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int i=x[p];i<=k[j];i++){
				v[i][j]=0;
			}
		}
		for(int j=1;j<=n;j++){
			for(int i=x[p];i<=k[j];i++){
				v[i][j]=t[i][j];
			}
		}
		
		for(int j=1;j<=n;j++){
			v[0][j]=0;
			v[k[j]+1][j]=0;
			for(int i=x[p];i<=k[j];i++){
				if(v[i-1][j]>0&&v[i+1][j]>0){
					int minn=1e16;
					
						minn=min(minn,min(v[i-1][j],v[i+1][j]));
						if(a[i][j]==v[i][j]) minn=min(minn,v[i][j]);
					
					v[i][j]+=minn;
				}else if(v[i-1][j]==0){
					int minn=1e16;
					
						minn=min(minn,v[i+1][j]);
						if(a[i][j]==v[i][j]) minn=min(minn,v[i][j]);
					
					v[i][j]+=minn;
				}else if(v[i+1][j]==0){
					int minn=1e16;
					
						minn=min(minn,v[i-1][j]);
						if(a[i][j]==v[i][j]) minn=min(minn,v[i][j]);
					
					v[i][j]+=minn;
				}
			
			}
			
		}
		for(int j=1;j<=n;j++){
			ans=max(ans,v[y[p]][j]);
		}
		ans+=w[x[p]];
		ans+=w[y[p]];
		cout<<ans<<"\n";
	}
	
	return 0;
}

