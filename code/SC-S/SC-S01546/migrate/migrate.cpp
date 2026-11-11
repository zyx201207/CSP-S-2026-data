#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
bool flagA=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]!=x[i-1]-x[i-2]&&i>2)flagA=0;
		}
		if(flagA){
			int q=x[2]-x[1];
			if(d>=x[n]-x[1])cout<<0;
			else{
				int c=0;
				while(q*(c+1)<=d){
					c++;
				}
				c+=2;
				cout<<n-c<<endl;
			}
		}
		t--;
	}	
	return 0;
}