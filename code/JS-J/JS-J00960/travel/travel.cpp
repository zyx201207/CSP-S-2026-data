#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[4],s2[4];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	char a=s1[0]+s1[1],b=s2[0]+s2[1],c=s1[2],d=s2[2];
	if(a==b)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int x=0,y=0;
	if(c==65||c==66||c==67)
		x=1;
	if(d==65||d==66||d==67)
		y=1;
	if(x==y)
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1)
		cout<<1;
	else
		cout<<"0";
	return 0;
}
