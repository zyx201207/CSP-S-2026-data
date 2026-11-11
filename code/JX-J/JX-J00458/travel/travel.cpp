#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char d1,d2;
	cin>>c1>>s1>>d1>>c2>>s2>>d2;
	if(c1==c2){
		cout<<'1';
		if(s1==s2){
			cout<<'1';
			if((d1<=67&&d2<=67)||(d1>=68&&d2>=68)){
				cout<<'1';
				if(d1-d2==1 || d2-d1==1){
					cout<<'1';
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
