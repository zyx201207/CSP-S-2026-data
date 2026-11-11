#include<bits/stdc++.h>
using namespace std;
int cx[18];
int zuo[100];
char s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	if(c1==c2){
		cout<<"1000";
	}
	
	return 0;
}