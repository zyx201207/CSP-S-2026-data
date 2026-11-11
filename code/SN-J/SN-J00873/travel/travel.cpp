#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1100;
	}
	else{
		cout<<0000;
	} 
	//for(int j=0;j<=s1.size()-1;j++){
	//	int n=s1;
	//for(int i=0;i<=s1.size();i++){
	//	if(i==A)  i==10;
	//	if(i==B)  i==11;
	//	if(i==C)  i==12;
	//	if(i==D)  i==13;
	//	if(i==F)  i==15;
	//	s1=n+i;
	//}
	//string k;
	//if(c1==c2){
	//	k=1;
	//	if(s1/100==s2/100){
	//		k=11;
	//		if(abs(s1%100-s2%100)==2){
	//			cout<<k=1110;
	//		}
	//		if(abs(s1%100-s2%100)==1){
	//			cout<<1111;
	//		}
	//	}else{
	//		cout<<k=1000;
	//	} 
	//}else{
	//	cout<<k=0000;
	//}
	
	return 0;
}
