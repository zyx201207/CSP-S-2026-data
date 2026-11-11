#include<bits/stdc++.h> 
using namespace std;
struct Node{
	string x,y,z;
};
Node a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	s1=a.y+a.z;
	s2=b.y+b.z;
	cin>>a.x>>s1>>b.x>>s2;
	if(a.x==b.x){
		cout<<"1";
		if(a.y==b.y){
			cout<<"1";
			if(a.z=="A"&&b.z=="B"||b.z=="B"&&b.z=="C"||b.y=="D"&&b.z=="E"){
				cout<<"1";
				if(a.z=="A"&&b.z=="C"){
					cout<<"0";
				}
				else cout<<"1";
			}
			else{
				cout<<"0"<<"0";
			}
		}
		else{
			cout<<"0"<<"0"<<"0";
		}
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}
