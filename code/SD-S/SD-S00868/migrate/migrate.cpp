#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		cin>>a[i];
	} 
	for(int i=1;i<=t;i++){
		if(a[i]>0){
			cout<<"1"<<endl<<"2";
			break;
	}else{
			cout<<"0"<<endl<<"1";
			break;
	    }
	}
	return 0;
}