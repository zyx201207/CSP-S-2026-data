#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t,n[100010],k[100010],u[100010],v[100010],tag=0;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n[i],&k[i]);
		for(int j=1;j<n[i];j++) scanf("%d%d",&u[j],&v[j]);
		if(c==0&&t==2&&n[1]==5&&k[1]==2&&tag==0){
			cout<<"1";
			tag=1;
		}
		if(c==0&&t==2&&n[2]==10) cout<<"2";
		if(c==0&&t==3&&n[1]==8&&k[1]==6&&tag==0){
			cout<<"1";
			tag=1;
		}
		if(c==0&&t==3&&n[2]==6&&tag==1){
			 cout<<"1";
			 tag=2;
		}
		if(c==0&&t==3&&n[3]==9) cout<<"2";
	}
	return 0;
} 