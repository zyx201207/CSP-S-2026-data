#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,m1,p1,q1;
	string n2,m2,p2,q2;
	cin>>n1>>n2>>m1>>m2;
	if(n1==m1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
    }
    if(n2[0]==0){
    	p1=int(n2[1])-48;
	}else{
		p1=int(n2[1])-38;
	}
	if(m2[0]==0){
    	q1=int(m2[1])-48;
	}else{
		q1=int(m2[1])-38;
	}
	if(p1==q1){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	p2=n2[2];
	q2=m2[2];
	if(p2<"D" && q2>"C"){
		cout<<"00";
		return 0;
	}else if(p2>"C" && q2<"D"){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if(q2>"C" && p2>"C"){
		cout<<"1";
	}else{
		if(p2=="A" && q2=="C"){
			cout<<"0";
		}else if(p2=="C" && q2=="A"){
			cout<<"0"; 
		}else{
			cout<<"1";
		}
	}
	return 0;
}
