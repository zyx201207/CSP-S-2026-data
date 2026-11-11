#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sa,ta,sd,td;
string a[200];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>ta>>sd>>td;
	if(sa!=sd){
		cout<<"0000";
		return 0;
	}
	string tq;
	tq=ta[0]+ta[1];
	string fq;
	fq=td[0]+td[1];
	if(tq!=fq){
		cout<<"1000";
		return 0;
	}
	string t;
	t=ta[2];
	string f;
	f=td[2];
	if(!((t=="A" && f=="B")||(t=="B" &&(f=="A" || f=="C"))||(t=="C" && f=="B") || (t=="D" && f=="F") || (t=="F" && t=="D"))){
		cout<<"1100";
		return 0;
	}
	char tp=ta[2];
	char fp=td[2];
	ll n=tp;
	ll m=fp;
	if(n-m!=1ll && n-m!=-1ll){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
