#include <bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a3,b3;
//zcy
int main()
{
freopen("travel3.in","r",stdin);
//freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>a1>>a2>>a3>>b1>>b2>>b3;
//cout<<a1<<a2<<a3<<b1<<b2<<b3;
if(a1==b1){
	cout<<1;
	}
else {
	cout<<"0000";
	return 0;
	}
if(a2==b2){
	cout<<1;
	}
else {
	cout<<"000";
	return 0;
	}
if(a3=='D') a3+=1;
if(b3=='D') b3+=1;
if((a3-'D')*(b3-'D')>0) cout<<1;
else cout<<0;
if(abs(a3-b3)==1) cout<<1;
else cout<<0;
return 0;
}
