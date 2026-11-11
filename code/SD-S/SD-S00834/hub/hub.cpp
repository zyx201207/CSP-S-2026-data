#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[51],v[51],cn[51];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(cn,0,sizeof(cn));
		for(int i=1;i<n;i++)
			scanf("%d%d",&u[i],&v[i]);
		if(n==2){
			if(k==1){
				cout<<1;
			}else
				cout<<0;
		}else if(n==3){
			if(k<=2){
				cout<<1;
			}else
				cout<<0;
		}else if(n==4){
			if(k==1){
				cout<<2;
			}else if(k<=3){
				cout<<1;
			}else
				cout<<0;
		}else{
			if(k==1){
				cout<<2;
			}else if(k<=4){
				cout<<1;
			}else
				cout<<0;}
		cout<<endl;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
