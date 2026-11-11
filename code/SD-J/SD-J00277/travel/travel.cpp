#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f(char a){
	return (a=='D'||a=='F');
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000"<<endl;
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000"<<endl;
	else if(f(s1[2])!=f(s2[2]))cout<<"1100"<<endl;
	else if(abs(s1[2]-s2[2])!=1)cout<<"1110"<<endl;
	else cout<<"1111"<<endl;
	return 0;
}

