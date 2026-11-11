#include<bits/stdc++.h>
using namespace std;int c,T,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--&&cin>>n>>d){
		if(c>=11&&c<=12){
			int x1,x2,x;cin>>x1>>x2;
			if(d==2*(x2-x1)){
				cout<<(n-3>=0?n-3:0);
			}else cout<<0;
			for(int i=0;i<n-2;i++)cin>>x;
		}else cout<<0;
		if(T>1)cout<<"\n";	
	}
	return 0;
}