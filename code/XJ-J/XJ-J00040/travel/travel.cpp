#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel .in","r",stdin);
	freopen("travel .out","w",stdout);
	int C1,C2,s1,s2,z1,z2;
      for(int i=1;i<=18;i++){
      	cin>>z1>>z2;
	 
			if(z1==z2){
				cout<<"1";
			}
			else {
				cout<<"0";
			}
	
	for(int i=01;i<=17;i++){
	   cin>>C1>>C2;
	for(int i='A';i<='F';i++){
	    cin>>s1>>s2;	
	while(C1!=01&&C1!=17&&C1==C2){
			if(s1=='A'&&s2=='B')
			cout<<"111"<<endl;
			if(s1=='B'&&s2=='C')
			cout<<"111"<<endl;
			 if(s1=='D'&&s2=='E')
			 cout<<"111"<<endl;
	        if(s1=='E'&&s2=='F')
			 cout<<"111"<<endl;
			 else
			 cout<<"110"<<endl;
	   }
	} 
  }
}

	return 0;
}
