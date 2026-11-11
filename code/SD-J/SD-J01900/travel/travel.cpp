#include <iostream>
using namespace std;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int a=10*(s2[0]-'0')+(s2[1]-'0');
	int b=10*(s4[0]-'0')+(s4[1]-'0');
	int c=s2[2]-'A'+1,d=s4[2]-'A'+1;
	if(s1==s3){
		cout<<1;
		if(a==b){
			cout<<1;
			if((c>=1&&c<=3&&d>=1&&d<=3)||(c>=4&&c<=5&&d>=4&&d<=5)){
				cout<<1;
				if(c<d) swap(c,d);
				if(c-d<=1) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
