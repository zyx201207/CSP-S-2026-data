#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
bool x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a<='C')x=1;
	else x=0;
	if(b<='C')y=1;
	else y=0;
	if(x!=y){
		cout<<"1100";
		return 0;
	}
	if(abs(a-b)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
