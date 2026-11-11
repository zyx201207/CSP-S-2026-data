#include<bits/stdc++.h>
using namespace std;
const int N=530,M=5e5+1145;
const long long inf=2e18;

int c,n,m,d,q,k[N],BE,ED;
long long aa,tt,ans,w[M];
vector<int> zh_way[M];
vector<long long> zh_wayt[M];
long long f[N][N];

inline void minn(long long &x,long long y){
    x=(x<=y?x:y);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&aa,&tt);
			zh_way[aa].push_back(i);
			zh_wayt[aa].push_back(tt);
		}
	}
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) f[i][j]=inf;
			
	for(int _=1;_<=m;_++){
		int len=zh_way[_].size();
		
		
	    for(int i=0;i<len;i++)
	        for(int j=i+1;j<len;j++){
		        int tx=zh_way[_][i];
		        int ty=zh_way[_][j];
	        	minn( f[tx][ty], zh_wayt[_][i]+zh_wayt[_][j] );
	        	minn( f[ty][tx], zh_wayt[_][i]+zh_wayt[_][j] );
			}
	            
	}
	
    for(int k=1;k<=n;k++)
    	for(int j=1;j<=n;j++)
    		for(int i=1;i<=n;i++){
    			minn(f[i][j],f[i][k]+f[k][j]);
    			minn(f[j][i],f[i][k]+f[k][j]);
			}
    
    while(q--){
    	scanf("%d%d",&BE,&ED);
    	int len1=zh_way[BE].size();
    	int len2=zh_way[ED].size();
    	
    	ans=inf;
		for(int i=0;i<len1;i++)
		    for(int j=0;j<len2;j++)
		        minn(ans,zh_wayt[BE][i]+zh_wayt[ED][j]+f[ zh_way[BE][i] ][ zh_way[ED][j] ]);
		        
		printf("%lld\n",ans+w[BE]+w[ED]);
	}
	return 0;
}
