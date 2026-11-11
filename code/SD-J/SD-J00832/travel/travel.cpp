#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int f1,f2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='F'||s1[2]=='D'){
		f1=1;
	}
	if(s2[2]=='F'||s2[2]=='D'){
		f2=1;
	}
	if(f1!=f2){
		cout<<"1100";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	//fclose("travel.in");
	//fclose("travel.out");
	return 0;
}
