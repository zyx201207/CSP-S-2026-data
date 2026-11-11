#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    num1=s1[2]-64;
    num2=s2[2]-64;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else if(s1[0]!=s2[0] or s1[1]!=s2[1]){
    	cout<<"1000";
    	return 0;
	}else if((num1<4 and num2>=4) or (num1>=4 and num2<4)){
		cout<<"1100";
		return 0;
	}else if(abs(num1-num2)!=1){
		cout<<"1110";
		return 0;
	} cout<<"1111";
    return 0;
}
