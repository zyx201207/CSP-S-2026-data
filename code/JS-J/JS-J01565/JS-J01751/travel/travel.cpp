#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1,car2;
	string seat1,seat2;
	cin>>car1>>seat1>>car2>>seat2;
	string roll1="",roll2="";
	roll1+=seat1[0];
	roll1+=seat1[1];
	roll2+=seat2[0];
	roll2+=seat2[1];
	bool f1,f2,f3,f4,f5;
	f1=(car1==car2);
	f2=(f1&&roll1==roll2);
	f3=f2&&((seat1[2]<='C'&&seat2[2]<='C')||(seat1[2]>='D'&&seat2[2]>='D'));
	f5=(seat1[2]>='D'&&seat2[2]>='D');
	f4=f3&&(f5||abs(seat1[2]-seat2[2])==1);
	cout<<f1;
	cout<<f2;
	cout<<f3;
	cout<<f4;
	return 0;
}
