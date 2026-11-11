#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[6]={0,0,0,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	int b1=s1[2]-'A',b2=s2[2]-'A';
	int a1=a[b1],a2=a[b2];
	if(a1+a2==1){
		cout<<"1100";
		return 0;
	}
	if(a1+a2==2){
		cout<<"1111";
	}else{
		if(b2-b1==1||b2-b1==-1){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}
	return 0;
} 
