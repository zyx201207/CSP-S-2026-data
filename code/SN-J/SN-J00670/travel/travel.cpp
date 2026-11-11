//maqinxin kunluzhongxue SN-J00670
#include<istream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string b,d,a,c;
	//char ;
		for(int i=1;i<=2;i++){
			cin>>a[1];
		}
		for(int i=1;i<=3;i++){
			cin>>b[i];
		}
		for(int i=1;i<=2;i++){
			cin>>c[1];
	}
		for(int i=1;i<=3;i++){
			cin>>d[i];
		}
	if(a[1]==c[1]&&a[2]==c[2]){
		cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
		
			if(((b[3]=='F'||b[3]=='D')&&(d[3]=='F'||d[3]=='D'))||((b[3]=='A'||b[3]=='B'||b[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'))){
				cout<<"1";
				
			  if(b[3]==d[3]-'1'||b[3]==d[3]+'1'){
			  	   cout<<"1";
					 
			  }
			  else
            	cout<<"0";
		}
		else
            	cout<<"00";
	}
		else
			cout<<"000";	
}	
	else{
		cout<<"0000";
	}
	return 0;
}
