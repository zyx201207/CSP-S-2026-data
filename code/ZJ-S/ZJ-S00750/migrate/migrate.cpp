#include<bits/stdc++.h> 
using namespace std;
long long int x[10000001];
pair<long long,long long>fl[10001][10001];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fl[i][j].first=INT_MAX/2;
				fl[i][j].second=0;
			}
		}
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(i!=j){
					if(x[j]-x[i]<=d){
						fl[i][j].first=1;
						fl[i][j].second=1;
						fl[j][i].first=1;
						fl[j][i].second=1;
					}
				}	
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(i!=j){
					if(x[j]-x[i]<=d){
						continue;
					}else{
						for(int k=0;k<n;k++){
							if(i==k||j==k)continue;
							if(fl[i][k].first+fl[k][j].first<fl[i][j].first){
								fl[i][j].first=fl[i][k].first+fl[k][j].first;
								fl[i][j].second=fl[i][k].second*fl[k][j].second;
								fl[j][i].first=fl[i][j].first;
								fl[j][i].second=fl[i][j].second;
							}else if(fl[i][k].first+fl[k][j].first==fl[i][j].first){
								fl[i][j].second+=fl[i][k].second*fl[k][j].second;
								fl[j][i].first=fl[i][j].first;							
							}
						}
					}
				}
				if(fl[i][j].second==2){
					ans++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
