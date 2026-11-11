#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int sum=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			sum+=x;
		}
		cout<<abs(sum)<<endl;
	}
}