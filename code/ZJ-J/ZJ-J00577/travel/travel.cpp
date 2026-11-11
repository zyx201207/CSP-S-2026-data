#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	bool f1=(s1[2]<='C');
	bool f2=(s2[2]<='C');
	if(f1==f2){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	bool f3=abs(int(s2[2])-int(s1[2]))==1;
	if(f3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
