#include<bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		cout<<'1';
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	//车厢 
	if(s1[2]==s2[2]){
		cout<<'0'<<'0'<<'0';
		return 0;
	} 
	else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';//排 
			if(s1[2]>='D'&&s2[2]>='D'){
			    cout<<'1';
			    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) {
				    if((s1[2]=='C'&&s2[2]>='D')||(s2[2]=='C'&&s1[2]>='D')){
					    cout<<'0';
				    }
				    else{
					    cout<<'1';
				    }
	        	}
		    else{
			    cout<<'0';
		    }
	        }//相邻 
		    else if(s1[2]>='D'&&s2[2]<'D'||s1[2]<'D'&&s2[2]>='D'){
					cout<<'0';
		    }
		    else{
					cout<<'1';
					if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) {
				    if((s1[2]=='C'&&s2[2]>='D')||(s2[2]=='C'&&s1[2]>='D')){
					    cout<<'0';
				    }
				    else{
					    cout<<'1';
				    }
	        	}
		    }//同一侧 
		}
		else{
			cout<<'0'<<'0'<<'0';
			return 0;
		}
   }	
	return 0;
}
