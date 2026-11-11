#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
    			if(x[j]-x[i]==2*d-1&&j-i==2*d-1){
					cnt++;
				}
  			 }
 		 }
		cout<<cnt<<"\n";
	}
	return 0;
}