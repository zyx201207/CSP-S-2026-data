#include<bits/stdc++.h>
using namespace std;
int c,t;
int ans;
int x[2000001];
int c1[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		for(int i=1;i<=n;i++){
			c1[i]=0;
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					c1[i]++;
				}
			}
			c1[i]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c1[j-1]-c1[i]==1&&j-i>2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
