#include<bits/stdc++.h>
using namespace std;
int f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					f3=1;
					int k=abs(s1[2]-s2[2]);
					if(k==1){
						f4=1;
					}
				}
			}else if(s1[2]=='D'||s1[2]=='E'){
				if(s2[2]=='D'||s2[2]=='E'){
					f3=1;
					int k=abs(s1[2]-s2[2]);
					if(k==1){
						f4=1;
					}
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}