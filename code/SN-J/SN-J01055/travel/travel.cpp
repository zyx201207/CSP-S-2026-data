#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
int c1[4],c2[4];
char sing1,sing2;
int s1[5],s2[5];
	for(int i=1;i<=3;i++){
	cin>>c1[i]>>s1[i]>>sing1>>c2[i]>>s2[i]>>sing2;
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<"1";
		
	}else{
		cout<<"0000";
	return 0;
	}	
	for(int i=1;i<=3;i++){
		if(s1[1]==s2[1]&&s2[1]==s2[2]){
			cout<<"1";
		}else{
	cout<<"000";
		return 0;
	
}    
	if(sing1=='A'){
				if(sing2=='B')cout<<"11";
	        	
			}else if(sing1=='A'){
				if(sing2=='C')cout<<"10";
				
			}else if(sing1=='B'){
				if(sing2=='C')cout<<"11";
				
			}else if(sing1=='B'){
			    if(sing2=='A')cout<<"11";
				
			}else if(sing1=='C'){
			    if(sing2=='A')cout<<"10";
				
			}else if(sing1=='C'){
			    if(sing2=='B')cout<<"11";
			
			}else if(sing1=='D'){
			    if(sing2=='F')cout<<"11";
			
			}else if(sing1=='F'){
			    if(sing2=='D')cout<<"11";
			
			}
	        else{
		        cout<<"00";
		
	        }
	

	}
//if(s1[1]==s2[1]&&s2[1]==s2[2]){
//			cout<<"1";
//		}else{
//	cout<<"000";
//		break;
	
}           //if(sing1=='A'){
		//		if(sing2=='B')cout<<"11";
	      //  	
		////	}else if(sing1=='A'){
			//	if(sing2=='C')cout<<"10";
		////		
	//		}else if(sing1=='B'){
	///			if(sing2=='C')cout<<"11";
		//		
		///u/	}else if(sing1=='B'){
	//		    if(sing2=='A')cout<<"11";
				
	//		}else if(sing1=='C'){
		//	    if(sing2=='A')cout<<"10";
	///			
	//		}else if(sing1=='C'){
	//		    if(sing2=='B')cout<<"11";
	////		
	//		}else if(sing1=='D'){
	//		    if(sing2=='F')cout<<"11";
			
	//		}else if(sing1=='F'){
	//		    if(sing2=='D')cout<<"11";
			
	//		}
	  //      else{
	//	        cout<<"00";
		
	      //  }
        }	
///	return 0;
//}





