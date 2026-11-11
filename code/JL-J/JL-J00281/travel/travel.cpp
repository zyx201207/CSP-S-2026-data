#include<iostream>
using namespace std;
int main(){
string C1,S1,C2,S2;
    int a,b,c,d = 0;
    for(int i = 0;i < 2;i++){
		if(C1[i] != C2[i]){
		cout<<"0";
		a = 1;
		break;
		}
	}
   if(a == 0) cout<<"1";
       for(int i = 0;i < 2;i++){
		if(S1[i] != S2[i]){
		cout<<"0";
		b = 1;
		break;
		}
	}
   if(b == 0){
	    cout<<"1";
		if(S1[2] > 'D' && S2[2] > 'D'){
			cout<<"1";
			c = 1;
		}
		if(S1[2] < 'C' && S2[2] < 'C'){
			cout<<"1";
			c = 1;
		}
	}
if(c == 0) cout<<"0";
      if(S1[2] - '1' == S2[2] || S1[2] - '1' == S1[2]){
		  cout<<"1";
		  d = 1;
	  }
 if(d == 0) cout<<"0";
return 0;
}
