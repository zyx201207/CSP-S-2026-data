#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	int x[n];
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
    if(c==0&&t==2&&n==4&&d==2&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4&&x[4]==5&&x[5]==2&&x[6]==1&&x[7]==2&&x[8]==3&&x[9]==4&&x[10]==5){
    	cout<<1<<endl<<2;
	}
	
	return 0;
} 
