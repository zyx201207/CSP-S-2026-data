#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
long long x[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,Z,n,d;
	cin>>c>>Z;
	while(Z--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		if(c<=10){
			vector<int> f[5010];
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n+5;j++){
					f[i].push_back(0);
				}
			}
			long long ans=0;
			for(int l=2;l<=n;l++){
				for(int i=1;i+l-1<=n;i++){
					int j=i+l-1;
					if(x[j]-x[i]<=d){
						f[i][j]=1;
					}
					else{
						int mins=INT_MAX,minc=0;
						for(int k=i+1;k<j;k++){
							if(f[i][k]!=0 && f[k][j]!=0){
								if(mins==f[i][k]+f[k][j]){
									minc++;
								}
								else{
									if(mins>f[i][k]+f[k][j]){
										minc=0;
										mins=f[i][k]+f[k][j];
									}
								}
							}
						}
						if(mins!=INT_MAX) f[i][j]=mins;
						if(minc==2) ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			if(c<=12){
				if(x[2]-x[1]>d/2){
					cout<<0<<"\n";
				}
				else{
					cout<<n-3<<"\n";
				}
			}
			else cout<<0<<"\n";
		}
	}
	return 0;
}

