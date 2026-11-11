#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=1,f2=1,f3=0,f4=0;
	int cc=c1.size();
	int ss=s1.size();
	for(int i=0;i<cc;i++){
		if(c1[i]!=c2[i]) f1=0;
	}
	if(!f1){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<ss-1;i++){
		if(s1[i]!=s2[i]) f2=0;
	}
	if(f2&&(s1[ss-1]=='D'||s1[ss-1]=='F')&&(s2[ss-1]=='D'||s2[ss-1]=='F')){
		f3=1;
	}
	if(f2&&(s1[ss-1]=='A'||s1[ss-1]=='B'||s1[ss-1]=='C')&&(s2[ss-1]=='A'||s2[ss-1]=='B'||s2[ss-1]=='C')){
		f3=1;
	}
	if(f2&&f3&&(abs(s1[ss-1]-s2[ss-1])==1)){
		f4=1;
	}
	if(f1) cout<<"1";
	else cout<<"0";
	if(f2) cout<<"1";
	else cout<<"0";
	if(f3) cout<<"1";
	else cout<<"0";
	if(f4) cout<<"1";
	else cout<<"0";
	return 0;
}