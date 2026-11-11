#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pan(int x,int y){
	int x1=x;
	int y1=y;
	if(65<=x1 and x1<=67 and 65<=y1 and y1<=67){
		return true;
	}
	if((x1==68 and y1<=70) or (x1==70 and y1==68)){
		return true;
	}
	return false;
}
bool pan1(int x,int y){
	if(x>=68){
		if(x-2==y or x+2==y){
			return true;
		}
	}
	if(x>=65 and x<=67){
		if(x-1==y or x+1==y){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int z1=int(s1[2]),q1=int(s2[2]);
	int l1=0,l2=0,l3=0,l4=0;
	if(c1==c2){
		l1=1;
	}
	if(l1==1 and s1[0]==s2[0] and s1[1]==s2[1]){
		l2=1;
	}
	if(l1==1 and l2==1 and pan(z1,q1)){
		l3=1;
	}
	if(l3==1 and pan1(z1,q1)){
		l4=1;
	}
	cout<<l1<<l2<<l3<<l4;
	return 0;
}
