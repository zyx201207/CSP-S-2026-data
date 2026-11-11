#include<bits/stdc++.h>
using namespace std;
long long x[5000005];
long long zd[114514];
long long cs[114514];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,f=0,sum=0;
	cin>>c>>t;
	while(t--){
//		memset(zd+1+n,0,sizeof zd);
//		memset(cs+1+n,0,sizeof cs);
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
		 	cin>>x[i];
		}
		sum=0;
		for(int o = 0;o<=n-4;o++){
			for(int i = 2;i<=n;i++){
				zd[i]=0;
				cs[i]=0;
			}
			zd[1] = 0;
			cs[1] = 0;
			f=0;
			for(int i = 2+o;i<=n;i++){
				f = 0;
				for(int j = 1+o;j<i;j++){
					if(x[i]-x[j] <= d){
						if(f == 1){
							if(zd[i] == zd[j] + 1){
								cs[i] ++;
							}
							else{
								zd[i] = min(zd[j] + 1,zd[i]);
								cs[i]=1;
							}
						}
						else{
							zd[i] = zd[j] + 1;
							cs[i]++;
							f=1;
						}
					}
				}
			}
			
			for(int i = 1;i<=n;i++){
				//cout<<cs[i]<<endl;
				if(cs[i] == 2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}




//kill race,really handsome,all the same age persons i don't want to jwdj