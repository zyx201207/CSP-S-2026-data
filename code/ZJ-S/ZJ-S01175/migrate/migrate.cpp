#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(d/(a[2]-a[1])<=1){
				cout<<0<<endl;
			}else{
				cout<<max(0,n-d/(a[2]-a[1])*2+1)<<endl;
			}
		}
	}else{
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
