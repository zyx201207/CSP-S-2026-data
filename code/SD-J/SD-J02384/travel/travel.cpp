#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s1,c2,s2;
	char p1,p2;
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
//	cout<<c1<<" "<<s1<<" "<<p1<<" "<<c2<<" "<<s2<<" "<<p2<<"\n";
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(s1!=s2){
		cout<<"1000";
		return 0;
	}else if(!((p1=='A'&&p2=='B')||(p2=='A'&&p1=='B')||(p1=='B'&&p2=='C')||(p2=='B'&&p1=='C')||(p1=='A'&&p2=='C')||(p2=='A'&&p1=='C')||(p1=='D'&&p2=='F')||(p2=='D'&&p1=='F'))){
		cout<<"1100";
		return 0;
	}else if(!((p1=='A'&&p2=='B')||(p2=='A'&&p1=='B')||(p1=='B'&&p2=='C')||(p2=='B'&&p1=='C')||(p1=='D'&&p2=='F')||(p2=='D'&&p1=='F'))){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
		return 0;
	}
	return 0;
} 
