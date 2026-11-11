#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		string h;
		string h2;
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				h+=s2[i];
				h2+=s4[i];
			}else break;
		}
		if(h==h2){
			if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')){
				int p=s2[2]-'A',p2=s4[2]-'A';
				if(abs(p-p2)==1){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000\n";
	}
	return 0;
}
