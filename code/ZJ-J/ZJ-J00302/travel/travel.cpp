#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1,a2,b1,b2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<1;
			char a3=a2[2],b3=b2[2];
			if((a3=='A'||a3=='B'||a3=='C')&&(b3=='A'||b3=='B'||b3=='C')){
				cout<<1;
				if((a3=='A'&&b3=='C')||(a3=='C'&&b3=='A')){
					cout<<"0";
					return 0;
				}else{
					cout<<1;
					return 0;
				}
			}else if((a3=='D'||a3=='F')&&(b3=='D'||b3=='F')){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}