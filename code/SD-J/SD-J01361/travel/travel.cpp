#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	int c1,c2,sum=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1=s1,p2=s2;
	p1[2]='0';
	p2[2]='0';
	if(c1==c2){
		sum++;
	}
	else{
		cout<<"0000";
		freopen("travel.out","w",stdout);
		return 0;
	}
	if(p1==p2){
		sum=sum*10+1;
		if(s1[2]<='C' && s2[2]<='C'){
			sum=sum*10+1;
		}
		else if(s1[2]>'C' && s2[2]>'C'){
			sum=sum*10+1;
		}
		else{
			cout<<sum<<"00";
			freopen("travel.out","w",stdout);
			return 0;
		}
	}
	else{
		cout<<sum<<"000";
		freopen("travel.out","w",stdout);
		return 0;
	}
	if(int(s1[2]-s2[2])==1 || int(s2[2]-s1[2])==1){
		if(s1[2]<='C' && s2[2]<='C'){
			sum=sum*10+1;
			cout<<sum;
			freopen("travel.out","w",stdout);
		}
		else if(s1[2]>'C' && s2[2]>'C'){
			sum=sum*10+1;
			cout<<sum;
			freopen("travel.out","w",stdout);
		}
		else{
			cout<<sum<<'0';
			freopen("travel.out","w",stdout);
		}
	}
	else{
		cout<<sum<<'0';
		freopen("travel.out","w",stdout);
	}
	return 0;
}
