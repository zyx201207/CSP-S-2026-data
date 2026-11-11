#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n<<endl;
	}
} 
