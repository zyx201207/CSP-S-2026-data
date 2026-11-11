#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	int c,t;
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		bool kk=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2) {
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]) 
					kk=false;
			}
		}
		if(kk){
			cout<<max(n-d-1,(long long)0)<<endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
