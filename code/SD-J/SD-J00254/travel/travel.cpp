#include<bits/stdc++.h>
using namespace std;
string number1,number2,node1,node2;
int sum1,sum2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>number1>>node1>>number2>>node2;
	sum1=node1[2]-'A';
	sum2=node2[2]-'A';
	if(number1==number2){
		cout<<1;
		if(node1[0]==node2[0]&&node1[1]==node2[1]){
			cout<<1;
			if((sum1<=2&&sum2<=2)||(sum1>2&&sum2>2)){
				cout<<1;
				if(abs(sum1-sum2)==1){
					cout<<1;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
