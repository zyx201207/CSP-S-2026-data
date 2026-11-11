#include<bits/stdc++.h>
using namespace std;
int p1,x1;
string p2,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>p1>>p2>>x1>>x2;
    if(p1==x1){
    	if(p2[0]+p2[1]==x2[0]+x2[1]){
    		if((p2[2]<='C'&&x2[2]<='C')||(p2[2]>='D'&&x2[2]>='D')){
    			if(p2[2]-1==x2[2]||p2[2]+1==x2[2]){
    				cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
} 
