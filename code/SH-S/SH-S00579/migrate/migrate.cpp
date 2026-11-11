#include<bits/stdc++.h>
using namespace std;
int n,c,t,d,ans=0,road=0;
long long x[2000005];
void countroad(int i,int j){
	if(d>x[j]-x[i]) road++;
	for(int k=i;k<j;k++){
		if(d>x[k]-x[i]&&d>x[j]-x[k]) road++;
	}
	if(road==2) ans++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migreate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				road=0;
				countroad(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
