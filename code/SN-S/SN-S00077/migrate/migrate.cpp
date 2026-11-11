#include <bits/stdc++.h>
using namespace std;
int x[200010];
int main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=c;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		int k=x[2]-x[1];
		if((x[3]-x[2])==k){
			if(x[n]%d==0){
				cout<<"0"<<endl;
			}else{
				cout<<x[n]/d+1<<endl;
			}
		}else{
			cout<<n<<endl; 
		}
		memset(x,0,sizeof(x));
	}
	return 0;
} 
