#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		f1=true;
	}
	else{
		cout<<"0000";
		return 0;
	}
	//统一车厢 
	if(f1){
		int x1=(s1[0]-'0')*10+(s1[1]-'0');
		int x2=(s2[0]-'0')*10+(s2[1]-'0');
		if(x1==x2){
			cout<<"1";
			f2=true;
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"000";
		return 0;
	}
	//同一排
	if(f1&&f2){
		char x1=s1[2];
		char x2=s2[2];
		if((x1<='C'&&x2<='C')||(x1>='D'&&x2>='D')){
			cout<<"1";
			f3=true;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	//同一侧
	if(f1&&f2&&f3){
		char x1=s1[2];
		char x2=s2[2];
		int a=x1-'0';
		int b=x2-'0';
		if(a>b){
			swap(a,b);
		}
		if(x1<='C'&&x2<='C'){
			if(a+1==b){
				cout<<"1";
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else{
			cout<<"1";
		}
	}
	else{
		cout<<"0";
		return 0;
	}
	//相邻 
	return 0;
} 
