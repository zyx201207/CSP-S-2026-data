#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	int sum=0; 
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		sum++;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		sum++;
	}
	if(b[2]=='E'||b[2]=='D'){
		sum--;
	}
	if(d[2]=='E'||d[2]=='D'){
		sum--;
	}
	if(sum==0){
		cout<<"1100";
		return 0;
	}
	sum=0;
	if(b[2]=='E'||b[2]=='D'){
		cout<<"1111";
		return 0;
	}
	if(b[2]!='B'&&d[2]!='B'){
		cout<<"1110";
		return 0;
	}
    cout<<"1111"; 
	return 0;
}
