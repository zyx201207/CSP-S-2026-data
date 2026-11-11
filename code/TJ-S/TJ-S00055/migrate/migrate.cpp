#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		bool flag=0;
		vector<int> x(n,0);
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(i>1){
				if(x[i]-x[i-1]==x[i-1]-x[i-2]) flag=1;
			}else flag=0;
		}
			if(flag){
				cout<<(n%d+n/d-1)*(n%d+n/d-1)/2+(n%d+n/d-1)*(n%d+n/d-1)%2<<'\n';
			}
		}
	
	return 0;
} 

