#include<bits/stdc++.h>//T1->travel
using namespace std;
const int N=100010;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<s1<<c2<<s2;
	if(c1==c2)cout<<'1';
	else {
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<'1';
	}else {
		cout<<"000";
		return 0;
	}
	
	int f1=s1[2]-'A',f2=s2[2]-'A';
	//cout<<' '<<f1<<f2;
	if((f1<3&&f2<3)||(f1>2&&f2>2)){
		cout<<'1';
	}else {
		cout<<"00";
		return 0;
	}
	
	if(f1<f2)swap(f1,f2);
	if(f1==5)f1--;//神秘出题人字典序阴人特判应对 
	if(f1-f2==1&&f1!=3){
		cout<<'1';
	}else {
		cout<<"0";
		return 0;
	}
	return 0;
}
