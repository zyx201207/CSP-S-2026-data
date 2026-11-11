#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<2;i++){
		if(c1==c2){
		cout<<"1";
	    }else{
		cout<<"0";
	    }
	    if(s1[i]==s2[i] && (s1[2]-s2[2]==-1 || s1[2]-s2[2]==1)){
	    	cout<<"1";
		}
		else if(s1[2]=='C' && s2[2]=='D' || (s1[2]=='D' && s2[2]=='C')){
			cout<<"0";
		}
		else cout<<"0"; 
	}
	
	return 0;
}  
