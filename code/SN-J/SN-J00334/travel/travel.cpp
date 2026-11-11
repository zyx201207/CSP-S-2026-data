#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int x1,x2,x3,x4;
int t1,t2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<s1.size();i++){
		x1=x1*10+(s1[i]-'0');
	}
	for(int i=0;i<s2.size()-1;i++){
		x2=x2*10+(s2[i]-'0');
	}
	for(int i=0;i<s3.size();i++){
		x3=x3*10+(s3[i]-'0');
	}
	for(int i=0;i<s4.size()-1;i++){
		x4=x4*10+(s4[i]-'0');
	}
	t1=s2[s2.size()-1]-'A';
	t2=s4[s4.size()-1]-'A';
//	cout<<t1<<t2<<endl;
	if(x1==x3) cout<<1;
	else cout<<0;
	if(x1==x3&&x2==x4) cout<<1;
	else cout<<0;
	if(x1==x3&&x2==x4&&((t1<=2&&t2<=2)||(t1>=3&&t2>=3))) cout<<1;
	else cout<<0;
	if(x1==x3&&x2==x4&&((t1<=2&&t2<=2)||(t1>=3&&t2>=3))&&(t1==t2+1||t2==t1+1)) cout<<1;
	else cout<<0;
	return 0;
}
