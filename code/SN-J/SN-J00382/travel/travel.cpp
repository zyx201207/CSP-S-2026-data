#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d;
char ch1,ch2;
bool b1,b2,b3,b4;
ll chk(char ch){
	if(ch=='A'||ch=='B'||ch=='C'){
		return 1;
	}
	if(ch=='D'||ch=='F'){
		return 2;
	}
}
ll chk1(char ch){
	if(ch=='F'){
		return 5;
	}
	else{
		return ch-'A'+1;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>ch1>>c>>d>>ch2;
	b1=(a==c);
	b2=(b1&&(b==d));
	b3=(b2&&(chk(ch1)==chk(ch2)));
	b4=(b3&&(abs(chk1(ch1)-chk1(ch2))==1));
	cout<<b1<<b2<<b3<<b4;
	return 0;
}

