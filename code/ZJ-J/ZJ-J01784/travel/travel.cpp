#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	
	int n=r2.size();
	
	if(r1==x1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	bool f=true;
	
	for(int i=0;i<n-1;i++){
		if(x2[i]!=r2[i]){
			f=false;
			break;
		}
	}
	
	if(!f){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	
//	cout<<r2[n-1]<<" ";
	if((r2[n-1]>='A'&&r2[n-1]<='C')&&(x2[n-1]>='A'&&x2[n-1]<='C')||((r2[n-1]>='D'&&r2[n-1]<='E')&&(x2[n-1]>='D'&&x2[n-1]<='E'))){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	if(r2[n-1]==x2[n-1]+1||r2[n-1]+1==x2[n-1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
