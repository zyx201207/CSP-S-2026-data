#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char dx[]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}int s,t;
	char ss,tt;
	s=(b[0]-'0')*10+b[1]-'0';
	t=(d[0]-'0')*10+d[1]-'0';
	ss=b[2],tt=d[2];
	if(s!=t){
		cout<<"1000";
		return 0;
	}
	cout<<"11";
	
	if(ss=='A'||ss=='B'||ss=='C'){
		if(tt=='D'||tt=='F'){
			cout<<"0";
		}else cout<<"1";
	}else{
		if(tt=='A'||tt=='B'||tt=='C'){
			cout<<"0";
		}else cout<<"1";
	}
	
	bool e=0;
	for(int i=0;i<5;i++){
		if(dx[i]==ss){
			if(i<4&&i!=2&&dx[i+1]==tt){
				e=1;
				break;
			}if(i>0&&i!=3&&dx[i-1]==tt){
				e=1;
				break;
			}
		}
	}
	if(!e){
		cout<<"0";
	}else{
		cout<<"1";
	}return 0;
}
