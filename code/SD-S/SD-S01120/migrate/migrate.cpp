#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000010],ans,f[5010],dist[5010][5010],cnt[5010][5010],judge[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		for(long long p=1;p<=t;p++){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>x[i];
			}
			long long kip=x[2]-x[1],kipmax=0;
			while(kipmax<=d){
				kipmax+=kip;
			}
			kipmax-=kip;
			kipmax/=kip;
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<kipmax;j++){
					if(i+kipmax+j<=n){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			ans=0;n=0;d=0;
    	}
	}else{
		for(long long p=1;p<=t;p++){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
			    for(int j=i;j<=n;j++){
				    dist[i][j]=1e9;
				}
			}
			for(long long i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
				int l=i;
				while(1){
					if(l==n&&x[l]-x[i]<=d) {
					    f[i]=l;	
					    dist[i][l]=1;
					    break;
					}else if(x[l]-x[i]>d) {
					    f[i]=l-1;
					    dist[i][l-1]=1;
						break;
				    }
				    dist[i][l]=1;
				    l++;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
				    for(int j=i;j<=n;j++){
				    	if(i<=k<=j){
				    		if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
						}else{
							continue;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
			    for(int j=i;j<=n;j++){
					if(dist[i][j]==1) judge[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int g=1;g<=n;g++){
		    		for(int i=1;i<=n;i++){
			    	    for(int j=1;j<=n;j++){
			    	    	if(i<=k<g<=j){
			    	    		if(dist[i][k]+dist[g][j]==dist[i][j]-1&&judge[k][g]==1) cnt[i][j]++;
			    			}else{
			    				continue;
			    			}
			    		}
			    	}
			    }
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cnt[i][j]=0;
					dist[i][j]=1e9;
					judge[i][j]=0;
					f[i]=0;
					x[i]=0;
				}
			}
    	}
	}
	return 0;
} 
//18:21还是写不出来，燃尽了 
