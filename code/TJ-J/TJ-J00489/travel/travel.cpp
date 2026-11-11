#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,m,n;
	bool flag1=0,flag2=0,flag3=0;
	cin>>x>>y>>m>>n;
	if(x==m){
		cout<<1;
		flag1=1;
	}else{
		cout<<0;
	}
	
	if(flag1&&y[0]==n[0]&&y[1]==n[1]){
		cout<<1;
		flag2=1;
	}else{
		cout<<0;
	}
	if(flag2&&(y[2]<=67&&n[2]<=67||y[2]>67&&n[2]>67)){
		flag3=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(flag3&&abs(y[2]-n[2])==1){
		
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
