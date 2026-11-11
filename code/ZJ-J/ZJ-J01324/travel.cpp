#include <bits/stdc++.h>
using namespace std;
vector <int>cc,ss,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c%10!=s%10){
		cout<<"0000";
		return 0;
	}else
	if(cc!=ss){
		cout<<"1000";
		return 0;
	}
	if(cc='A',ss=B){
		if((cc='B',ss='A')){			
			if((cc='A',ss='C')){			
				if(cc='C',ss='A'){
					if((cc='D',ss='F')){			
						if((cc='F',ss='D')){			
				
						}else{
							cout<<"1100";
							return 0;
						}		
					}else{
						cout<<"1100";
						return 0;
					}				
				}else{
					cout<<"1100";
					return 0;
				}	
			}else{
				cout<<"1100";
				return 0;
			}		
		}else{
			cout<<"1100";
			return 0;
		}				
	}else{
		cout<<"1100";
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
