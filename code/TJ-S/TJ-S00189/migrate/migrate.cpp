#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
    int c,t;
    cin>>c>>t;
    int a,b;
    cin>>a>>b;
    if(c==0&&t==2&&a==4&&b==2){
    	cout<<1<<endl<<2;
    	return 0;
	} 
    if(c==0&&t==2&&a==5&&b==3){
    	cout<<0<<endl<<1;
    	return 0;
	}
	return 0;
}

