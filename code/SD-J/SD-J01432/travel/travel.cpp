#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,t="";
	cin>>c1>>s1>>c2>>s2;
	int k='C'-'0';
	if(c1==c2){
		cout<<1; 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(((s1[2]-'0')<=k&&(s2[2]-'0')<=k)||((s1[2]-'0')>k&&(s2[2]-'0')>k)){
				cout<<1;
				if(abs((s1[2]-'0')-(s2[2]-'0'))==1){
					cout<<1;
				}else cout<<0;
				return 0;
			}else cout<<0<<0;
			return 0;
		}
		cout<<0<<0<<0;
		return 0;
	}
	cout<<0<<0<<0<<0;
	
	return 0;
}
