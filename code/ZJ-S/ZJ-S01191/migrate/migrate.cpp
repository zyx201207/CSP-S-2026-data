#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,x[5],sxx;
		cin>>n>>d;
		for(int i=1;i<=2;i++) cin>>x[i];
		for(int i=3;i<=n;i++) cin>>sxx;
		long long xkd=x[2]-x[1];
		if(d-d%xkd-xkd<=0){
			cout<<0<<endl;
		}else{
			long long dkd=2*(d-d%xkd)-xkd;
			cout<<(xkd*(n-1)-dkd)/xkd+1<<endl;
		}
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}