#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,b1,b2;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)if(c1[i]!=c2[i])f=1;
	if(f){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)if(s1[i]!=s2[i])f=1;
	if(f){
		cout<<"1000";
		return 0;
	}
	a1=s1[2]-'A';a2=s2[2]-'A';
	if(a1==0||a1==1||a1==2)b1=1;
	else b1=2;
	if(a2==0||a2==1||a2==2)b2=1;
	else b2=2;
	if(b1!=b2){
		cout<<"1100";
		return 0;
	}
	if(a1>a2)swap(a1,a2);
	if((a1==4&&a2==6)||a2-a1==1)cout<<"1111";
	else cout<<"1110";
	return 0;
}
