#include<bits/stdc++.h>
using namespace std;
long long t,n,d,x[2000010],ans[2000010],vis[2000010],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cnt = 0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
			if(i < 2)continue;
			if(x[i]-x[1] <= d){
				ans[i] = 1;
			} 
			else{
				for(long long j=2;j<i;j++){
					if(x[i]-x[j] <= d){
					
						if(ans[i] == 0)ans[i] = x[j] +1;
						else {
							if(vis[i] == 0 && ans[i] == x[j] +1)vis[i] = 1;
							else if(vis[i] != 0 && ans[i] == x[j] +1)vis[i] = 0;
							else ans[i] = min(ans[i],x[j] +1);
						}
					}
					
				}
			}
		}
		for(long long i=1;i<=n;i++){
			ans[i] = 0;
			if(vis[i])cnt ++;
			vis[i] = 0;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
