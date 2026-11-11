#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char c1,d1;
	cin>>a>>c>>c1>>b>>d>>d1;
	if(a==b){
		
		if(c==d){
			
			if(c1-d1<=2){
				if(c1==d1+1||c1+1==d1){
					if(c1=='C'&&d1=='D'){
						cout<<"1100";
						return 0;	
					}else if(c1=='D'&&d1=='C'){
						cout<<"1100";
						return 0;
					}else{
						cout<<"1111";
						return 0;
					}
					
				}else{
					if(c1=='D'&&d1=='F'){
						cout<<"1111";
						return 0;
					}else if(c1=='F'&&d1=='D'){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
		
	}else{
		cout<<"0000";
		return 0;
	}

	
	return 0;
}
