#include<bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;
int a1,a2,b1,b2,sa,sb;

bool c(int a,int b){
	if(a>=1&&a<=3){
		if(b>=1&&b<=3)return 1;
		else return 0;
	}
	else{
		if(b>=4&&b<=5)return 1;
		else return 0;
	}
}

bool l(int a,int b){
	if(abs(a-b)==1) return 1;
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	int len1=s1.size(),len2=s2.size(),len3=s3.size(),len4=s4.size();
	a1=(s1[0]-'0')*10+s1[1]-'0';
	b1=(s3[0]-'0')*10+s3[1]-'0';
	a2=(s2[0]-'0')*10+s2[1]-'0';
	b2=(s4[0]-'0')*10+s4[1]-'0';
	sa=s2[2]-'A'+1;
	sb=s4[2]-'A'+1;
	if(a1!=b1){
		cout<<"0000\n";
	}else if(a2!=b2){
		cout<<"1000\n";
	}else if(!c(sa,sb)){
		cout<<"1100\n";
	}else if(!l(sa,sb)){
		cout<<"1110\n";
	}else{
		cout<<"1111\n";
	}
	return 0;
} 
