#include<bits/stdc++.h>
using namespace std;
int n;
long long d,x[2000001];
int fs(int hc,int j,int zl){
	if(x[j]-x[hc]<=d&&j-hc==1) return 1;
	int sum=0;
	for(int k=hc;k<=j;k++){
		if(x[k]-x[hc]<=d) sum+=fs(k,j,zl);
		else break;
		if(sum>2) return sum;
	} 
	return sum;
}
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int zl=fs(i,j,1); 
				if(zl==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

