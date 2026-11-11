#include <bits/stdc++.h>
#define int long long
using namespace std;
int flag1,flag2,flag3,flag4;
char c1[10],c2[10],s1[10],s2[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1+1>>s1+1>>c2+1>>s2+1;
	flag1=flag2=flag3=flag4=1;
	for(int i=1;i<=2;i++)
		if(c1[i]!=c2[i]) flag1=0;
	if(flag1){
		for(int i=1;i<=2;i++)
			if(s1[i]!=s2[i]) flag2=0;		
	}
	else flag2=0;
	if(flag2){
		if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')) flag3=1;
		else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')) flag3=1;
		else flag3=0;
	}
	else flag3=0;
	if(flag3){
		if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='C'&&s2[3]=='B')) flag4=1;
		else if((s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')) flag4=1;
		else flag4=0;
	}
	else flag4=0;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}