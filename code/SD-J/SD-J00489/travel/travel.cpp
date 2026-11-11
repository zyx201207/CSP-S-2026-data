#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10,mod=998244353;
string a,b,s1,s2;
bool f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(s1[2]>='A'&&s1[2]<='C') f1=1;
	else f1=0;
	if(s2[2]>='A'&&s2[2]<='C') f2=1;
	else f2=0;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	if(f1==f2){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	char c1=max(s1[2],s2[2]),c2=min(s1[2],s2[2]);
//	cout<<c1<<" "<<c2<<endl;
	if(c1-1==c2){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
