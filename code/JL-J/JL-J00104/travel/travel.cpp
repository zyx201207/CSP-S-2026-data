#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	// cout<<c1<<" "<<c2<<endl;
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
				int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
				if(s1[2]>='A' && s1[2]<='C'){
					if(abs(a-b)==1){
						cout<<"1111"<<endl;
					}
					else{
						cout<<"1110"<<endl;
					}
				}
				else{
					cout<<"1111"<<endl;
				}
			}
			else{
				cout<<"1100"<<endl;
			}
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
}