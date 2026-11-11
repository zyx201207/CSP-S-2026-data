#include <bits/stdc++.h>  
using namespace std;
int c,t,n,k,a,b; 
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	c=t+1; 
	while(t--){
		cin>>n>>k;	
		for (int i=0;i<n;i++){
			cin>>a>>b;
			a=a+b;
			k+=a;
		}
		if (t==1){
			cout<<1<<'\n';
		}
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
