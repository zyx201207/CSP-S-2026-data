#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a="";
	int r=0,r1=0,r2=0;
	if(c1==c2){
		a+="1";
		r=1;
	}
	else{
		a+="0";
	}
	if(s1[0]+s1[1]==s2[0]+s2[1] and r==1){
		a+="1";
		r1=1;
	}
	else{
		a+="0";
	}
	if(r==1 and r1==1 and (s1[2]=='A' or s1[2]=='B' or s1[2]=='C') and (s2[2]=='A' or s2[2]=='B' or s2[2]=='C')){
		a+="1C";
		cout<<s1[2]<<" "<<s2[2]<<"\n";
		r2=1;
	}
	else if(r==0 and r1==1 and (s1[2]=='D' or s1[2]=='F') and (s2[2]=='D' or s2[2]=='F')){
		a+="1CC";
		r2=1;
	}
	else{
		a+="0";
	}
	if(a[0]=='1' and a[1]=='1' and a[2]=='1'){
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				a+="1";
			}
		}
		if(s1[2]=='B'){
			if(s2[2]=='A' or s2[2]=='C'){
				a+="1";
			}
		}
		if(s1[2]=='C'){
			if(s2[2]=='B'){
				a+="1";
			}
		}
		if(s1[2]=='D'){
			if(s2[2]=='F'){
				a+="1";
			}
		}
		if(s1[2]=='F'){
			if(s2[2]=='D'){
				a+="1";
			}
		}
		if(a.length()==3){
			a+="0";
		}
	}
	else{
		a+="0";
	}
	cout<<a;
	return 0;

}