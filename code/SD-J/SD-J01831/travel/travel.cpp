#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
string c1,c2,s1,s2;
int flag=1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	TIE;
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){//是否在同一车厢 
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	int ss1=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
	int ss2=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	
	if(ss1==ss2){//同一排 
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	char l1=s1[2],l2=s2[2];
	
	if((l1<='C'&&l2<='C')||(l1>='D'&&l2>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((char)(l1+1)==l2||(char)(l1-1)==l2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
/*
02 01A 02 01B
02 01A 02 01C
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
