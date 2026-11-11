#include<bits/stdc++.h>
using namespace std;
int a,b;
char aa1,aa2,aa3,bb1,bb2,bb3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa1>>aa2>>aa3>>b>>bb1>>bb2>>bb3;
	int a1=(int)aa1-48;
	int a2=(int)aa2-48;
	int a3=(int)aa3;
	int b1=(int)bb1-48;
	int b2=(int)bb2-48;
	int b3=(int)bb3;
	if(a3==68) a3++;
	if(b3==68) b3++;
	int ab;
	if(a3>=b3) ab=a3-b3;
	else ab=b3-a3;
	if(a==b)
		cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(a1==b1&&a2==b2)
		cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((a3==65&&b3==66)||(a3==65&&b3==67)||(a3==66&&b3==65)||(a3==66&&b3==67)||(a3==67&&b3==65)||(a3==67&&b3==66)||(a3==69&&b3==70)||(a3==70&&b3==69))
		cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(ab==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
