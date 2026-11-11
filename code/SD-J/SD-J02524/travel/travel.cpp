#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int f1,f2,f3,f4;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[0]==c2[0]) f1=1;
	if(f1!=0){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
		}
		if(f2!=0){
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				f3=1;	
			}
		}
	}
	if(f1&&f2&&f3){
		if(abs((int)(s1[2])-(int)(s2[2]))==1){
			f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
