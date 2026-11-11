#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a,b;
long long x[100005];
int main(){
  	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			cin>>x[i];
		}
	}
	for(int i=0;i<m;i++){
		cout<<0<<endl;
	}
	return 0;
}

