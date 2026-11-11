#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int r=s1[2],x=s2[2];
			bool a=(x=='D'||x=='F'),b=(r=='D'||r=='F');
			if(a==true&&b==true){
				cout<<"11";
			}else if(a==false&&b==false){
				cout<<"1";
				int c=abs(r-x);
				if(c==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}