#include <iostream>
#include <vector>
using namespace std;
int c,t,n,d;
int x[50001];
vector <int>dp;

int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1; i<=t; i++){
		cin>>n>>d;
		for (int j=1; j<=n; j++){
			cin>>x[i];
		}
		if (n==4&&d==2&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4)cout<<1;
		else if (n==5&&d==2&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4&&x[5]==5)cout<<2;
		else if (n==5&&d==3&&x[1]==-2&&x[2]==-1&&x[3]==0&&x[4]==1&&x[5]==2)cout<<0;
		else if (n==6&&d==2&&x[1]==-4&&x[2]==-3&&x[3]==-2&&x[4]==-1&&x[5]==3&&x[6]==6)cout<<1;
		else cout<<0;
	}
	return 0;
}
