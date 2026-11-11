#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c[]={1,1,1,2,2};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[2]=='F'){
		s1[2]='E';
	}
	if(s2[2]=='F'){
		s2[2]='E';
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&c[s1[2]-'A']==c[s2[2]-'A']){
		cout<<1;
	}else{
		cout<<0;
	}
	int f=abs((int)s1[2]-s2[2]);
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&c[s1[2]-'A']==c[s2[2]-'A']&&f==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	system("fc .ans .out");
	return 0;
}
*/
