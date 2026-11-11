#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			if(('C'-a2[2])>=0&&('C'-b2[2])>=0){
			    if(abs(a2[2]-b2[2])==1)cout<<"1111";
			    else cout<<"1110";
			}
			else if(('C'-a2[2])<0&&('C'-b2[2])<0){
			    if(abs(a2[2]-b2[2])==1)cout<<"1111";
			    else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
}
