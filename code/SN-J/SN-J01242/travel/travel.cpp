#include<bits/stdc++.h>
using namespace std;
int split0(string s){
	string num=s.substr(0,2);
	//cout<<num;
	return stoi(num);
}
int split1(string s1,string s2,string y1,string y2){
	string c1=s1.substr(2,1);
	string c2=s2.substr(2,1);
	if((((c1[0]>='A'&&c1[0]<='C')&&(c2[0]>='A'&&c2[0]<='C'))||
		((c1[0]>='D'&&c1[0]<='E')&&(c2[0]>='D'&&c2[0]<='E')))&&
		y1==y2&&split0(s1)==split0(s2))return 1;
	else return 0;
}
int check(string s1,string s2,string y1,string y2){
	string c1=s1.substr(2,1);
	string c2=s2.substr(2,1);
	int n1=c1[0]-'A',n2=c2[0]-'A';
	if((abs(n1-n2)==1)&&split1(s1,s2,y1,y2)==1&&y1==y2)return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;//同节 
	else cout<<0;
	if(split0(s1)==split0(s2)&&c1==c2)cout<<1;//同节&&同排 
	else cout<<0;
	//if(split1(s1,s2))
	cout<<split1(s1,s2,c1,c2);//同节&&同排 && 同侧 
	cout<<check(s1,s2,c1,c2);
	return 0;
} 
