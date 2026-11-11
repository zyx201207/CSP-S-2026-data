#include<iostream>
using namespace std;
const int A=2e6+6;
int c,T;int n,w;int num[A],a[A];
int tu[A][A][2];
int main(){
cin>>T;
for(int t=1;t<=T;t++){
	feropen("migrate.in","r",stdin);
	feropen("migrate.out","w",stdout);
	cin>>n>>w;
	int aa;
	for(int i=1;i<=n;i++){
		cin>>aa;
		a[i]=aa;
		num[i]=aa-1;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)tu[i][j][1]=0;
			else{
				tu[i][j][1]=a[i]-a[j];
			}
		}	
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++){
			if(tu[i][j][1]==tu[i][k][1]+tu[j][k][1])tu[i][j][0]++;
			if(tu[i][j][1]>tu[i][k][1]+tu[j][k][1]){
			tu[i][j][1]=tu[i][k][1]+tu[j][k][1];tu[i][j][0]=0;}
		}		
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=ans+tu[i][1][0];
	}
	cout<<ans;
	
}
	return 0;
}
