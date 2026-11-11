#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt,flag,x[2000005],d,c,T;
int ans;
void dfs(int deep,int now,int cnt,int en){
	if(deep==cnt&&now==en){
		sum++;
		return;
	}
	if(sum>2||deep>cnt){
		return;
	}
	int ii=now+1;
	while(x[ii]-x[now]<=d&&ii<=n){
		dfs(deep+1,ii,cnt,en);
		ii++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int k=i,l=i,cnt=1;
				while(k<=j){
					if(x[k]-x[l]>d){
						l=k;
						cnt++;
					}
					k++;
				}
				sum=0;
				dfs(0,i,cnt,j);
				if(sum==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
}
