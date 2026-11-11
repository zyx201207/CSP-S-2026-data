#include<bits/stdc++.h> 
using namespace std;
char a[10],a1[10],b[10],b1[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>a1[0]>>a1[1]>>a1[2];
	cin>>b[0]>>b[1]>>b1[0]>>b1[1]>>b1[2];
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if (a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if ((a1[2]<'D'&&b1[2]<'D')||(a1[2]>'C'&&b1[2]>'C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if (a1[2]+1==b1[2]||b1[2]+1==a1[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
