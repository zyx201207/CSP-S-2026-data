#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
char c11,c12,c21,c22,c23,c31,c32,c41,c42,c43;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>c12>>c21>>c22>>c23>>c31>>c32>>c41>>c42>>c43;
	if(c11==c31&&c12==c32){
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(c21==c41&&c22==c42){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if(c23=='A'&&c43=='B'){
		cout<<"11";
		return 0;
	}
	else if(c23=='A'&&c43=='C'){
		cout<<"10";
		return 0;
	}
	else if(c23=='A'&&c43=='D'){
		cout<<"00";
		return 0;
	}
	else if(c23=='A'&&c43=='F'){
		cout<<"00";
		return 0;
	}
	else if(c23=='B'&&c43=='A'){
		cout<<"11";
		return 0;
	}
	else if(c23=='B'&&c43=='C'){
		cout<<"11";
		return 0;
	}
	else if(c23=='B'&&c43=='D'){
		cout<<"00";
		return 0;
	}
	else if(c23=='B'&&c43=='F'){
		cout<<"00";
		return 0;
	}
	else if(c23=='C'&&c43=='A'){
		cout<<"10";
		return 0;
	}
	else if(c23=='C'&&c43=='B'){
		cout<<"11";
		return 0;
	}
	else if(c23=='C'&&c43=='D'){
		cout<<"00";
		return 0;
	}
	else if(c23=='C'&&c43=='F'){
		cout<<"00";
		return 0;
	}
	else if(c23=='D'&&c43=='F'||c43=='D'&&c23=='F'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

