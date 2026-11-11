#include<bits/stdc++.h>
using namespace std;
int Rn,Rs,Xn,Xs;
char a,b,t,d;
int main()
{
freopen("travel.in",r,stdin);
freopen("travel.out",w,stdout);
ios::sync_with_stdio(o);
cin.tie(0);
cin>>Rn>>Rs>>Xn>>Xs;
if(Rn==Xn)
	cout<<"1";
else
	cout<<"0";
if(Rs[1]==Xs[1]&&Rs[2]==Xs[2])
	cout<<"1";
else
	cout<<"0";
a=Rs[3];
b=Xs[3];
if(a=='A'||a=='B'a=='C')
{	
if(b=='A'||b=='B'||b=='C')
		cout<<"1";
	else
		cout<<"0";
}
else t++;
if(t==1)
	if(a=='D'||a=='F')
{	
if(b=='D'||b=='F')
{
cout<<"11";
return 0;
}
		
	else
	{
	cout<<"00";
	return 0;
	}
		
}
if(a+1==b||a-1==b)
	cout<<"1";
else
	cout<<"0";
return 0;
}
