#include <bits/stdc++.h>
using namespace std;
#define int long long 
int w[500005];
int a[505][3];
int t[505][3];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,sum=0;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%lld",&w[i]);
	}for(int i=0;i<n;i++){
		
		scanf("%lld",&k);
		for(int j=0;j<k;j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",x,y);
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				
			
				if(a[i][j]==x){
					sum+=w[x-1]+t[i][0];
				}else if(a[i][j]==y){
					sum+=w[x-1]+t[i][0];
				}else if(a[i][0]==a[i+1][0]&&a[i][0]==a[i+1][1]){
					sum+=t[i][0]+=t[i][1];
				}
		}
		}
		
	}cout<<sum;
	
	
	
	
	return 0;
} 
