#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&b>='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	int c;
	if(a>=b)
	c=a-b;
	else
	c=b-a;
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&c==1||a>='D'&&b>='D'&&c==1){
		cout<<1;
	}else{
		cout<<0;
	}
}
