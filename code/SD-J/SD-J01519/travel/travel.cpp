#include<bits/stdc++.h>
using namespace std;
#define int long long
int getpai(string piao){
	return (piao[0]-'0')*10+(piao[1]-'0');
}
int che1,che2;
string str1,str2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>che1>>str1>>che2>>str2;
	if(che1!=che2){
		cout<<"0000\n";
		return 0;
	}
	char ch1=str1[2],ch2=str2[2];
	int pai1=getpai(str1),pai2=getpai(str2);
	if(pai1!=pai2){
		cout<<"1000\n";
		return 0;
	}
	if((ch1=='D' && ch2!='F') || (ch1=='F' && ch2!='D') || (ch1=='A' && (ch2!='B' && ch2!='C')) || (ch1=='B' && (ch2!='A' && ch2!='C')) || (ch1=='C' && (ch2!='A' && ch2!='B'))){
		cout<<"1100\n";
		return 0;
	}
	if(ch1=='B' || ch2=='B'){
		cout<<"1111\n";
		return 0;
	}
	else if((ch1=='D' && ch2=='F') || (ch1=='F' && ch2=='D')){
		cout<<"1111\n";
		return 0;
	}
	else cout<<"1110\n";
	return 0;
}
