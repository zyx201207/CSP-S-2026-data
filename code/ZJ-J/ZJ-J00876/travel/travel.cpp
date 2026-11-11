#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=0,ce1,ce2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans++;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				ce1=1;
			}else{
				ce1=2;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				ce2=1;
			}else{
				ce2=2;
			}
			if(ce1==ce2){
				ans++;
				if(abs(int(s1[2]-s2[2]))==1&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))){
					ans++;
				}
			}
		}
	}
	for(int i=1;i<=ans;i++){
		cout<<1;
	}
	for(int i=1;i<=4-ans;i++){
		cout<<0;
	}
	return 0;
}
