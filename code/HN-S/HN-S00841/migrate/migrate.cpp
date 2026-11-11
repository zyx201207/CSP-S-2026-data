#include<bits/stdc++.h>
using namespace std;
int a[2000006];
map<int,map<int,int> >dp,pd;
int n,d;
int gdp(int x,int y){
	if(a[y]-a[x]<=d){
		return 1;
	}else{
		return dp[x][y];
	}
}
int pdg(int x,int y){
	if(a[y]-a[x]<=d){
		return 1;
	}else{
		return pd[x][y];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		dp.clear();
		pd.clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				for(int k=j+1;k<i+j-1;k++){
					if(gdp(j,k)+gdp(k,i+j-1)>gdp(j,i+j-1)){
						dp[j][i+j-1]=gdp(j,k)+gdp(k,i+j-1);
						pd[j][i+j-1]=pdg(j,k)*pdg(k,i+j-1);
					}
					if(gdp(j,k)+gdp(k,i+j-1)==gdp(j,i+j-1)){
						pd[j][i+j-1]+=pdg(j,k)*pdg(k,i+j-1);
					}
				}
				if(pdg(j,i+j-1)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

