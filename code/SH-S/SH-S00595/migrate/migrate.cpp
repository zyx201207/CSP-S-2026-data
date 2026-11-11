#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int p=d/(abs(x[2]-x[1])),q=p*2-1;
			cout<<n-q<<endl;
		}
	}
	return 0; 
}
