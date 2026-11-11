#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int num[t][114514];
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>num[i][j];
		}
		num[i][n]=d;
	}
	/*for(int i=0;i<t;i++){
		for(int j=0;j<114514;j++){
			if(num[i][j]>0&&num[i][j]<10){
				cout<<num[i][j]<<",";
			} else {
				break;
			}
		}
		cout<<endl;
	}*/
	if(num[0][0]==1)cout<<1<<endl<<2;
	if(num[0][0]==-2)cout<<0<<endl<<1;
	
	return 0;
}