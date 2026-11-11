#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,zb[2000005],jj[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>zb[i];
			if(i>1) jj[i-1]=abs(zb[i]-zb[i]);
		}int sum=0;
		if(d%2==0){
			for(int j=1;j<=n;j++){
				if(jj[j]>d)sum++;
			}
			cout<<(n-3)*(n-4)/2-sum+1<<'\n';
		}
		else if(d%2) cout<<0<<'\n';
	}
	return 0;
}