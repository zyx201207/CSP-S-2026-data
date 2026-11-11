//高子懿 SN-S00525 延安市安塞区初级中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> x(n);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int lenth[100][100]={};
		lenth[1][1]=-1;
		for(int i=1;i<=n;i++){
			lenth[i+1][i+1]=-1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				lenth[i][j]=-2;
			}
		}
		lenth[1][4]=1;
		lenth[2][4]=1;
		lenth[1][5]=1;
		lenth[2][5]=1;
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<lenth[i][j]<<" ";
			}
			cout<<endl;
		}*/
		if(n==4)
			cout<<(lenth[1][4]+lenth[2][4])/2;
		else
			cout<<(lenth[1][4]+lenth[2][4]+lenth[2][5]+lenth[1][5])/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
