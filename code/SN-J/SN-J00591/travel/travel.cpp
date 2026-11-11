#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cnt++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cnt++;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				cnt++;
				if(abs(s1[2]-s2[2])==1) cnt++;
			}
		}
	}
	for(int i=1;i<=cnt;i++) cout<<'1';
	for(int i=cnt+1;i<=4;i++) cout<<'0';
}
