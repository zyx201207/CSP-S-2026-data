#include<bits/stdc++.h>
using namespace std;
string s1,s2,set1,set2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	cin>>s1>>set1>>s2>>set2;
	if(s1==s2){
		cout<<1;
		if(set1[0]==set2[0]&&set1[1]==set2[1]){
			cout<<1;
			int p1=set1[2]-'A';
			int p2=set2[2]-'A';
			if((p1<=2&&p2<=2)||(p1>=3&&p2>=3)){
				cout<<1;
				if(abs(p1-p2)==1){
					cout<<1;
				} 
				else cout<<0;
			}
			
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	 
} 
