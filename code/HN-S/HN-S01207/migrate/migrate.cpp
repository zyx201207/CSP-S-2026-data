#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		int n,d;
		cin>>n>>d;
		int sum=0;
		vector<int> x(n+1),u(n);
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1) u[i]=1;
			if(i>1) u[i]=x+u[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
			}
		}
	}
	return 0;
}
