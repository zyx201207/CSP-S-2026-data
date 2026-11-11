#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[10];
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]==1;
	}else{
		cout<<"0000";
		return 0;
	}
	bool flag=true;
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		flag==true;
	}else{
		flag==false;
	}
	if(flag){
		a[1]==1;
	}else{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[3]=='B'||s2[3]=='C'){
			a[2]==1;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[3]=='C'){
			a[2]==1;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='A'||s2[3]=='B'){
			a[2]==1;
		}
	}else if(s1[2]=='D'){
		if(s2[2]=='E'){
			a[2]==1;
		}
	}else if(s1[2]=='E'){
		if(s2[2]=='D'){
			a[2]==1;
		}
	}else{
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			a[3]==1;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			a[3]==1;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='B'){
			a[3]==1;
		}
	}else if(s1[2]=='D'){
		if(s2[2]=='E'){
			a[3]==1;
		}
	}else if(s1[2]=='E'){
		if(s2[2]=='D'){
			a[3]==1;
		}
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
