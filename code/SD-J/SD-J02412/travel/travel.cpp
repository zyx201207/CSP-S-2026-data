#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>x1>>x2;
	if(s1==x1){
		cout<<1;
		if(s2[0]==x2[0] && s2[1]==x2[1]){
		   cout<<1;
		    if((s2[2]<='C' && x2[2]<='C') || (s2[2]>'C' && x2[2]>'C')){
		        cout<<1;
		        if(s2[2]-x2[2]==1 || x2[2]-s2[2]==1){
		        	cout<<1;
				}else{
					cout<<0;
				}
	        }else{
	        	cout<<"00";
			}
	    }else{
	    	cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
