#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	char a[1],b[2],c[1],d[2];
		cin>>a>>b>>c>>d;
		if(a[1]==c[1]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		if(b[1]==d[1]){
			cout<<"1";		
		}else{
			cout<<"0";
			}
		if((b[2]<'A'||b[2]=='A'||b[2]=='C'||b[2]<'C')&&(d[2]>'A'||d[2]=='A'||d[2]=='C'||d[2]<'C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
			cout<<"1";
		}else{
			cout<"0";
		}
		if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'){
			cout<<"1";
		}else{
			cout<<"0";
		}
		cout<<endl;
	
		return 0;
}
