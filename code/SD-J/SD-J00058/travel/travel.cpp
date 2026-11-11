#include<iostream>
#include<cmath>
using namespace std;
int n,a[1000005],f[1000005];
string cl,sl,cz,sz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cl>>sl>>cz>>sz;
	if(cl==cz){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sl[0]==sz[0]&&sl[1]==sz[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(sl[2]>='D'&&sz[2]>='D'||sl[2]<'D'&&sz[2]<'D'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(sl[2]-sz[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
} 
