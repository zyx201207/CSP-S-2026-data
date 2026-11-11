#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool check(int a,int b){
	if((a==65&&(b==66||b==67))||
	   (a==66&&(b==65||b==67))||
	   (a==67&&(b==65||b==66))||
	   (a==68&&b==69)||(a==69&&b==68)){
		return 1;
	}
	return 0;
}
bool check2(int a,int b){
	if((a==65&&b==66)||(a==66&&b==65)||
	   (a==67&&b==66)||(a==66&&b==67)||
	   (a==68&&b==69)||(a==69&&b==68)){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		int x,y;
		int a,b;
		x=(s1[0]-'0')*10+(s1[1]-'0');
		y=(s2[0]-'0')*10+(s2[1]-'0');
		a=(s1[2]);
		b=(s2[2]);
		if(x==y){
			cout<<"1";
			if(check(a,b)){
				cout<<"1";
				if(check2(a,b)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}