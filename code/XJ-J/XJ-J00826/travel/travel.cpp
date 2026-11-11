#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c,c1;
	string s,s1;
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<1;
		if(s[1]==s1[1] && s[0]==s1[0]){
			cout<<1;
			int len;
			if(s[2]=='F'){
				len=5;
			}else{
				len=s[2]-'A'+1;
			}
			int len1;
			if(s1[2]=='F'){
				len1=5;
			}else{
				len1=s1[2]-'A'+1;
			}
			if(len<=3 && len1<=3 ||  len>3 && len1>3){
				cout<<1;
				if(len+1==len1 || len-1==len1){
					cout<<1;
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
