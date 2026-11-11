#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen(stdin,"r",travel.in);
	freopen(stdout,"w",travel.out);
	string s1,s2,s3,s4;
	cin >> s3 >> s1 >> s4 >> s2;
	bool seat[4]={1,0,0,0};
	for(int i=0;i<2;i++){
		if(s3[i]!=s4[i]){
			seat[0]=0;
		}
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&seat[0]){
		seat[1]=1;
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&seat[0]&&seat[1]){
		seat[2]=2;
	}
	ll n,m;
	switch(s1[2]){
		case 'A':n=1;break;
		case 'B':n=2;break;
		case 'C':n=3;break;
		case 'D':n=4;break;
		case 'F':n=5;break;
	}
	switch(s2[2]){
		case 'A':m=1;break;
		case 'B':m=2;break;
		case 'C':m=3;break;
		case 'D':m=4;break;
		case 'F':m=5;break;
	}
	ll a=max(n,m),b=min(n,m);
	if(a-b==1&&seat[0]&&seat[1]&&seat[2]){
		seat[3]=1;
	}
	for(int i=0;i<4;i++){
		cout << seat[i];
	}
	return 0;
}
