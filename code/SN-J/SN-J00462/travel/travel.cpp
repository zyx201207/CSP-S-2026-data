#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b==d){
    	cout<<0<<0<<0<<0;
    	return 0;
	}
    for(int i=0;i<b.size();i++){
    	if(a==c){
			cout<<1;
			break;
		}
		else {
			cout<<0;
			break;	
		}
	}
		
	for(int i=0;i<b.size();i++){
		if(b[i]==d[i]&&b[i+1]==d[i+1]){
			cout<<1;
			break;
		}
		else{
		cout<<0<<0<<0;
		return 0;
	}
	}
	for(int i=0;i<b.size();i++){
		if(b[i+2]<='C'&&d[i+2]<='C'||b[i+2]>='D'&&d[i+2]>='D'){
			cout<<1;
			break;
		}		
		else{
			cout<<0<<0;
			return 0;
		}
	}
	
	for(int i=0;i<b.size();i++){
		if(b[i+2]=='C'&&d[i+2]>='D'){
			cout<<0;
			break;
		}
		else if(b[i+2]-d[i+2]==1||d[i+2]-b[i+2]==1){
			cout<<1;
			break;
		}
		else{
			cout<<0;
			break;
		}
	}
    return 0;
}
