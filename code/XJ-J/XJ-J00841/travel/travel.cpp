#include <bits/stdc++.h>
using namespace std;
const int N=18;
string s1,s2,zuo1,zuo2;
int t1=0,t2=0;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>s1>>zuo1>>s2>>zuo2;
	
	t1=zuo1[0]-'0';
	t1=t1*10+zuo1[1]-'0';
	t2=zuo2[0]-'0';
	t2=t2*10+zuo2[1]-'0';
	int n1=zuo1[2]-'A'+1,n2=zuo2[2]-'A'+1;
	if(s1==s2){
		cout<<"1";
		if (t1==t2){
			cout<<"1";
			
			if (n1<=3 && n2<=3 || n1 >=4 && n2>=4){
				cout<<"1";
				
				if (n1-1==n2 || n1+1==n2){
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else{
				cout<<"00";
			}
		} else{
			cout<<"000";
		}
	} else{
		cout<<"0000";
	} 
	
	
	
	return 0;
} 
