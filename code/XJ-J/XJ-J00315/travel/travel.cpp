#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	string s1,s2;
	string cmp="ABCDF";
	cin>>c1>>s1>>c2>>s2;
	int a1,a2;
	
	
	if(c1==c2){
		cout<<1;
		
		
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			
			for(int i=0;i<5;i++){
				if(s1[2]==cmp[i]) a1=i;
				if(s2[2]==cmp[i]) a2=i;
			}
			
			
			if((a1>=0 and a1<=2 and a2>=0 and a2<=2) or (a1>=3 and a1<=4 and a2>=3 and a2<=4)){
				cout<<1;
				if(a1-a2==1 or a2-a1==1){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
				
		}else{
			cout<<00;
			return 0;
		}
		
		
		
	}else{
		cout<<000;
		return 0;
		}
		
		
	}
	else{
		cout<<0000;
		return 0;
	}
}
