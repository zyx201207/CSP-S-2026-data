#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;int kk,sum;
long long x[2000006];
void dfs(int now,int ed,int dep){
	if(now==ed){
		if(kk>dep){
			kk=min(kk,dep);
			sum=0;
		}
		if(kk==dep) sum++; 
		
		return;
	}
	for(int i=now+1;i<=ed;i++){
		if(x[i]-x[now]<=d){
			dfs(i,ed,dep+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;int p=1;
		for(int k=1;k<n;k++){
			if(x[k+1]-x[k]>d){
				for(int i=p;i<=k;i++){
					for(int j=i+1;j<=k;j++){
						kk=1e18;
						sum=0;
						dfs(i,j,0);
						if(sum==2) ans++; 
					}
				}
				p=k+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

