#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool panduan(string a,string b){
	if(a.size()!=b.size())return 0;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
bool panduan2(string a,string b){
	for(int i=0;i<2;i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
bool panduan3(string a,string b){
	if((a[2]=='A'&&b[2]=='B')||(a[2]=='A'&&b[2]=='C')||(a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='A')||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))
		return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(panduan(c1,c2)){
		cout<<1;
		if(panduan2(s1,s2)){
			cout<<1;
			if(panduan3(s1,s2)){
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout<<1;
				}else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}