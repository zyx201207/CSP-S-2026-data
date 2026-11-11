//SN-J00757 何沛玲 西安市黄河中学 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	int n,s;
	string m,w;
	cin>>n>>s>>m>>w;
	if(n=s){
		cout<<"1";
		if(m[0]=w[0]){
			cout<<"1";
			if(m[1]=w[1]){
				cout<<"1";
				if(m[2]="D"||"F"){
					if(w[2]="D"||"f"){
						cout<<"1";
			    	}
					if(m[2]="A"&& w[2]="B"){
						cout<<"1";
					}
					if(m[2]="B"||m[2]="C"){
						if(w[2]="BH"||w[2]="C"){
						cout<<"1";
						}
			    	}
					
				}else{cout"0";
				}
				
			}else{cout<<"0";
			}
		}else{cout<<"0";
		}	
		
		}
    }else{cout<<"0000";
	}
	return 0;
}

