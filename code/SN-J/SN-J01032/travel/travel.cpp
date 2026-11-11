#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,m,n;
	char a[3],b[3];
	cin>>x>>a>>y>>b;
	if(x==y){
		cout<<"1";
	}
	else{
	    cout<<"0000";
	    return 0;
	} 
	if(a[0]==b[0]){
		if(a[1]==b[1]){
			cout<<"1";
		}
		else{
		    cout<<"000";
		    return 0; 
		} 
	}
	else{
	    cout<<"000";
	    return 0;
	} 
	if(a[2]=='F'&&b[2]=='F'){
		if(a[2]=='D'&&b[2]=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(a[2]-b[2]<3&&b[2]-a[2]<3){
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if(a[2]-b[2]==1&&b[2]-a[2]==1){
		if(a[2]!='D'&&b[2]!='D'){
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
} 
