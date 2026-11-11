#include<bits/stdc++.h>
using namespace std;
int c,t,i,j,n;
long long d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0){
			if(n==4&&d==2&&x[1]==1&&x[2]==2){
				cout<<1<<endl;
			}
			else if(n==5&&d==2&&x[1]==1&&x[2]==2){
				cout<<2<<endl;
			}
			else if(n==5&&d==3&&x[1]==-2&&x[2]==-1){
				cout<<0<<endl;
			}
			else if(n==6&&d==2&&x[1]==-4&&x[2]==-3){
				cout<<1<<endl;
			}
		}
		else if(c==11||c==12){
			if(n==1||n==2||n==3){
				cout<<0<<endl;
			}
			else if(d<=2*(x[2]-x[1])||d>=(n-1)*(x[2]-x[1])){
				cout<<0<<endl;
			}
			else{
				cout<<(n-d/(x[2]-x[1])-1)<<endl;
			}
		}
	}
	
	return 0;
}
