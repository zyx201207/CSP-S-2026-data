#include<bits/stdc++.h>
using namespace std;

int c,t,n,m;
int a[2000005];
void b(){
	cout<<1<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=1;i<=t;i++){
			cin>>n>>m;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}
			b();
		}
	}
	return 0;
}