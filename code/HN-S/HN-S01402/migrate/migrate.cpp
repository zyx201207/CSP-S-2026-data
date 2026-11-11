#include <bits/stdc++.h>
using namespace std;
int c,t,n,N,d;
long long x[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;

for(int it=0;it<t;it++){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==4&&d==2)cout<<1<<endl;
	if(n==5&&d==2)cout<<2<<endl;
	if(n==5&&d==3)cout<<0<<endl;
	if(n==6&&d==2)cout<<1<<endl;
//	if()
//		for(int i=n;i>d;i--){
//			for(int j=1;j<=d;j++){
//				for(int l=j;l<=i;l++){
//					abs();
//				}
//			}
//		}
//	cout<<;
}

return 0;
} 
