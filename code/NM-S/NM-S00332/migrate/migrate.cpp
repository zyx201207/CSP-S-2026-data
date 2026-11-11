#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	int n,int d;
		cin>>n>>d;
		int a;
		for(int i=1;i<=n;i++) cin>>a;
		if(a<0)cout<<d%n-2<<endl;
    	else cout<<d%n+2<<endl;
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
