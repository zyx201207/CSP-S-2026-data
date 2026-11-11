#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[1000010],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+2;j<=n;j++){
				int fl=j-i+1;
				for(int k=i+1;k<=j;k++){
					if(x[k]-x[i]>d)fl--;
					
				}if(fl==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}