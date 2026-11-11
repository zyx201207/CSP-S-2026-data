#include<bits/stdc++.h>
using namespace std;
int car,num,car2,num2;
char n,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car>>num>>n>>car2>>num2>>n2;
	if(car!=01&&car!=16&&car==car2){
		cout<<"1";
		if(num==num2){
			cout<<"1";
			if(n>=65&&n<68&&n2>=65&&n2<68){
					cout<<"1";
		if(n+1==n2||n-1==n2){
			if(n!=n2){
					cout<<"1";
			}else{
				cout<<"0";
			}
			
			}else{
				cout<<"0";
		}
	}else{
	if(n>=68&&n<70&&n2>=68&&n2<70){
						cout<<"1";
						if(n+1==n2||n-1==n2){
							if(n!=n2){
					cout<<"1";
			}else{
				cout<<"0";
			}
			}else{
				cout<<"0";
		}
					}else{
						cout<<"00";
					}
		
	}
}else{
	cout<<"000";
}
	}else{
		cout<<"0000";
	}
	return 0;
} 
