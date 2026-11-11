#include<bits/stdc++.h>
using namespace std;
int n,a[2000010],c,t,m;
bool fff=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		fff=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				cout<<1;
				fff=1;
			}
		}
//		cout<<fff<<endl;
		if(fff==0){
			int x=m/(a[2]-a[1]);
			if(x<=2)cout<<n-x-1<<endl;
			else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
/*
0 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
*/
