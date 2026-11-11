#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	//1.che xiang
	if(c==cc)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//2.pai
	if(s[0]==ss[0]&&s[1]==ss[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	//3.ce
	if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'))cout<<"1";
	else if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	//4.xiang lin
	if(s[2]>ss[2]&&s[2]==ss[2]+1)cout<<"1";
	else if(s[2]<ss[2]&&s[2]+1==ss[2])cout<<"1";
	else cout<<"0";
	return 0;
}
