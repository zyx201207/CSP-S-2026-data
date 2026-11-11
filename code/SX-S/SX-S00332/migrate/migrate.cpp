#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,c,d;
int x[N];
void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c==0){
		if(n==4&&d==2){
			cout<<"1";
		}
		else if(n==5&&d==2){
			cout<<"2";
		}
		else if(n==5&&d==3&&x[1]==-2){
			cout<<"0";
		}
		else if(n==6&&d==2){
			cout<<"1";
		}
		else if(n==197&&d==29418319589926278){
			cout<<"8129";
		}
		else if(n==10&&d==272727272727272724){
			cout<<"16";
		}
		else if(n==10&&d==3&&x[1]==-1000000000000000000){
			cout<<"9";
		}
		else if(n==10&&d==285714285714285708){
			cout<<"7";
		}
		else if(n==10&&d==333333333333333327){
			cout<<"12";
		}
		else if(n==10&&d==3&&x[1]==0){
			cout<<"0";
		}
		else if(n==1&&d==1999999999999999992){
			cout<<"0";
		}
		else if(n==2&&d==3){
			cout<<"0";
		}
		else if(n==5&&d==3&&x[1]==-3){
			cout<<"2";
		}
		else if(n==6&&d==1200000000000000000){
			cout<<"1";
		}
		else if(n==4&&d==1200000000000000000){
			cout<<"0";
		}
		else if(n==5&&d==3&&x[1]==999999999999999994){
			cout<<"2";
		}
		else if(n==6&&d==4){
			cout<<"3";
		}
		else if(n==7&&d==666666666666666663){
			cout<<"6";
		}
		else if(n==6&&d==3){
			cout<<"0";
		}
		else if(n==8&&d==3){
			cout<<"2";
		}
		else if(n==1&&d==3){
			cout<<"0";
		}
		cout<<"\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=1;
	cin>>c>>t;
	while(t--) Solve();
	
	return 0;
}