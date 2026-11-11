#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string a=s1.substr(0,s1.length()-1);
		string b=s2.substr(0,s2.length()-1);
		if(a==b){
			cout<<"1";
			int len1=s1.length()-1;
			int len2=s2.length()-1;
			char c=s1[len1];
			char d=s2[len2];
			if(('A'<=c&&c<='C'&&'A'<=d&&d<='C')||(('D'<=c&&c<='F'&&'D'<=d&&d<='F'))){
				cout<<"1";
				if(d+1==c||d-1==c||d=='D'&&c=='F'||c=='D'&&d=='F'){
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

