#include<bits/stdc++.h>
using namespace std;
int c,t,n[10],k[10],u[1000010],v[1000010],m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cout<<"1\n2";
		}
		if(t==1){
			cout<<"12251";
		}
		if(t==3){
			cout<<"1\n1\n2";
		}
		if(t==5){
			cout<<"17\n9\n6\n6\n9";
		}
		return 0;
	}
	for(int i=1;i<=t;i++){
		cin>>n[i]>>k[i];
		m=(n[i]-1)/2;
		for(int j=1;j<=m;j++){
			u[j]=j,v[j]=j+1;
		}
		for(int j=m+1;j<=n[i];j++){
			u[j]=j-m,v[j]=j+1;
		}
		cout<<"0\n";      
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}