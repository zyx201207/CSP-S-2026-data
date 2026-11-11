#include <bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    int c,t;
    cin>>c>>t;
    for(int T=0;T<t;T++){
    	int n,d;
    	long long ans=1,tree=0;
    	cin>>n>>d;
    	int x[1+n];
    	for(int i=1;i<=n;i++){
    		cin>>x[i];
		}
		bool map[n+1][n+1];
		map[0][0]=true,map[0][1]=true,map[1][0]=true;
		for(int i=1;i<n;i++)for(int j=2;j<=n;j++){
			if(d>=max(x[i],x[j])-min(x[i],x[j]))map[i][i+1]=true;
		}
		int p[n+1][n+1]={0};
		for(int i=1;i<=n-4 ;i++){
			bool dds=true;
			for(int j=0;j<4;j++){
				dds=dds&&map[i+j][i+1+j];
				if(i==1){
					tree++;
				}
				if(!dds)break;
				map[i][i+j+1]=true&&map[i+j][i+1+j];
			}
			if(dds)ans++;
		}
		
		printf("%lld\n",ans); 
	}
    return 0;
}
