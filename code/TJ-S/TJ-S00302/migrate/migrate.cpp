#include <bits/stdc++.h>
using namespace std;

int a[2000005];
int dis[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(n<=3){
			cout<<0;
			return 0;
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			dis[i]=a[i]-a[i-1];
		}
		int lm=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i]!=dis[j]){
					break;
				}
				else {
					lm++;
				}
			}
		}
		if(lm==n*(n-1)/2){
			cout<<0;
			continue;
		}
		
	}
	
	return 0;
}
