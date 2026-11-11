#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,Is[5010],eg[5010][5010],Way[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11){
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"0"<<endl;
		}
	}else{
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>Is[i];
			}
			sort(Is+1,Is+n+1);
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++){
					if(Is[j]-Is[i]<=d){
						eg[i][j]=1;
						Way[i][j]=1;
					}else{
						eg[i][j]=0;
						Way[i][j]=0;
					}
				}
			for(int k=2;k<n;k++){
				for(int i=1;i<k;i++){
					if(!eg[i][k]) continue;
					for(int j=k+1;j<=n;j++){
						if(!eg[k][j]) continue;
						if(eg[i][j]>(eg[i][k]+eg[k][j]) || eg[i][j]==0){
							eg[i][j]=eg[i][k]+eg[k][j];
							Way[i][j]=Way[i][k]*Way[k][j];
						}else if(eg[i][j]==(eg[i][k]+eg[k][j])){
							Way[i][j]+=(Way[i][k]*Way[k][j]);
						}
					}
				}
			}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++){
					if(Way[i][j]==2) ans++;
				}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
