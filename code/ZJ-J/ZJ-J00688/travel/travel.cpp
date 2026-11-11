//Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,a1,a2;
	cin>>c1>>s1>>c2>>s2;
	int i1,i2,s3,s4;
	i1=(c1[0]-'0')*10+(c1[1]-'0');
	i2=(c2[0]-'0')*10+(c2[1]-'0');
	s3=(s1[0]-'0')*10+(s1[1]-'0');
	s4=(s2[0]-'0')*10+(s2[1]-'0');
	a1=s1[2];a2=s2[2];
	if(a1=="F") a1="E";
	if(a2=="F") a2="E";
	//cout<<i1<<" "<<i2<<" "<<s3<<" "<<s4<<" "<<a1<<" "<<a2<<endl;
	if(i1!=i2){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	if(s3!=s4){
		cout<<"000"<<endl;
		return 0;
	}
	cout<<1;
	if((a1=="A"||a1=="B"||a1=="C")&&(a2=="D"||a2=="E")){
		cout<<"00"<<endl;
		return 0;
	}else if((a2=="A"||a2=="B"||a2=="C")&&(a1=="D"||a1=="E")){
		cout<<"00"<<endl;
		return 0;
	}
	cout<<1;
	if(a1=="A"&&a2=="C"){
		cout<<0<<endl;
		return 0;
	}else if(a2=="A"&&a1=="C"){
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
} 
