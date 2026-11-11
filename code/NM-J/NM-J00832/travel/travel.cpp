#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freeopen(travel.in,"r",stdin);
    freeopen(travel.out,"w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<"1";
	}else {
    	cout<<"0"<<"0"<<"0"<<"0";
    	return 0;
	}
    for(int i=1;i<=1;i++){
    	if(s1[i]==s2[i]){
    		cout<<"1";
		}else{
			cout<<"0"<<"0"<<"0";
			return 0;
		}
	}
    for(int i=3;i<=3;i++){
    	if(s1[3]-s2[3]<=2||s2[3]-s1[3]<=2){
			cout<<"1";
		}else{

			cout<<"0"<<"0";
			return 0;
		}
		if(s1[3]-s2[3]<=1||s2[3]-s1[3]<=1){
			cout<<"1";
		}else{

			cout<<"0";
		}
	}


    fclose(stdin);
    fclose(stdout);
    return 0;
}
