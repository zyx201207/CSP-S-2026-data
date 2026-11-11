#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
char c_1[10],s_1[10],c2[10],s2[10];
bool f[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1+1>>s_1+1>>c2+1>>s2+1;
	if(c_1[1]==c2[1] && c_1[2]==c2[2])
		f[1]=1;
	else
		f[1]=0;
	if(f[1]){
		if(s_1[1]==s2[1] && s_1[2]==s2[2])
			f[2]=1;
		else
			f[2]=0;
	}
	else
		f[2]=0;
	if(f[2]){
		if((s_1[3]=='A' || s_1[3]=='B' || s_1[3]=='C') && (s2[3]=='A' || s2[3]=='B' || s2[3]=='C'))
			f[3]=1;
		else if((s_1[3]=='D' || s_1[3]=='F') && (s2[3]=='D' || s_1[3]=='F'))
			f[3]=1;
		else
			f[3]=0;
	}
	else
		f[3]=0;
	if(f[3]){
		if(s_1[3]=='D' || s_1[3]=='F')
			f[4]=1;
		else if(s_1[3]=='A'){
			if(s2[3]=='B')
				f[4]=1;
			else
				f[4]=0;
		}
		else if(s_1[3]=='B')
			f[4]=1;
		else if(s_1[3]=='C'){
			if(s2[3]=='B')
				f[4]=1;
			else
				f[4]=0;
		}
	}
	else
		f[4]=0;
	for(int i=1;i<=4;i++)
		cout<<f[i];
	return 0;
}
