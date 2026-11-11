#include <bits/stdc++.h>
using namespace std;

string cr,sr,cx,sx;
char sr0,sx0;

bool check(){
	if(sr[2]=='A'){
		if(sx[2]=='B' || sx[2]=='C'){
			return 1;
		}
	}else if(sr[2]=='B'){
		if(sx[2]=='A' || sx[2]=='C'){
			return 1;
		}
	}else if(sr[2]=='C'){
		if(sx[2]=='B' || sx[2]=='A'){
			return 1;
		}
	}else if(sr[2]=='D'){
		if(sx[2]=='F'){
			return 1;
		}
	}else if(sr[2]=='F'){
		if(sx[2]=='D'){
			return 1;
		}
	}
	return 0;
}

bool next(){
	if((sr[2]+1==sx[2]) || (sr[2]-1==sx[2])) return 1;
	return 0;
} 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	
	//判断是否在同一节车厢
	if(cr==cx){
		cout<<1;
		
		//判断是否在同一节车厢的同一排
		if(sr[0]==sr[0]&&sr[1]==sr[1]){
			cout<<1;
			
			//判断是否在同一节车厢的同一排，且位于过道的同一侧 
			if(check()){
				cout<<1;
				
				//判断是否相邻 
				if(next()){
					cout<<1;
					
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
