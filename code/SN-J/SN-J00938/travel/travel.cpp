#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else cout<<"0";
	for(int i=0;i<s1.size();i++){
		for(int j=0;j<s2.size();j++){
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
			    cout<<"1";
			    break;
		    }else{
		    	cout<<"0";
		    	break;
			}
			
			if(abs(s1[s1.size()-1]-s2[s2.size()-1])<=2&&s1[s1.size()-1]!='D'&&s1[s1.size()-1]!='F'){
				
				cout<<"1";
				break;
			}else{
		    	cout<<"0";
		    	break;
	    	}
	    	
			if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1&&s1[s1.size()-1]!='D'&&s1[s1.size()-1]!='C'){
				cout<<"1";
				break;
			}else{
			    cout<<"0";
			    break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
