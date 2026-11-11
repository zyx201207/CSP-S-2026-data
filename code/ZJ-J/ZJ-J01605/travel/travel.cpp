#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,num1,num2,z1,z2;
bool vis1,vis2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9') num1+=s1[i];
		else z1+=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9') num2+=s2[i];
		else z2+=s2[i];
	}
	if(num1==num2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(z1>="A"&&z1<="C") vis1=true;
	else vis1=false;
	if(z2>="A"&&z2<="C") vis2=true;
	else vis2=false;
	if(vis1==vis2) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	int delta=0;
	for(int i=0;i<z1.size();i++) delta+=z1[i]-'A';
	for(int i=0;i<z2.size();i++) delta+=z2[i]-'A';
	if(abs(delta)==1||((z1=="D"&&z2=="F")&&(z1!="C"&&z2!="D"))) cout<<"1";
	else cout<<"0";
	return 0;
}
