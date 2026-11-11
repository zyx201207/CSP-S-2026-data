#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>c1+1>>s1+1>>c2+1>>s2+1;
	int c11=c1[1],c12=c1[2],c21=c2[1],c22=c2[2];
	if(c11!=c21||c12!=c22){
		cout<<"0000";
		return 0;
	}else cout<<"1";
int s11=s1[1],s12=s1[2],s21=s2[1],s22=s2[2];
	if(s11!=s21||s12!=s22){
		cout<<"000";
		return 0;
	}else cout<<"1";
	int x=s1[3],y=s2[3];
	if(x==68&&y!=69||x==69&&y!=68){
		cout<<"00";
		return 0;
	}else if(x==65||x==66||x==67){
		if(y==68||y==69){
			cout<<"00";
			return 0;
		}else{
		cout<<"1";
		}
	}
	if(abs(x-y)==1) cout<<"1";
	else cout<<"0";
	return 0;
}