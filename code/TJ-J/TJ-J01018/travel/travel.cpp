#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s2[2]=='F'){
		s2[2]='E';
	}
	if(s4[2]=='F'){
		s4[2]='E';
	}
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			int u=s2[2]-'A',v=s4[2]-'A';
			int o=max(u,v),p=min(u,v);
			if(o<=2&&p<=2||o>=3&&p>=3){
				cout<<1;
				if(o-p==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
		
	}else{
		for(int i=0;i<4;i++){
			cout<<0;
		}
		return 0;
	}
	
	return 0;
} 
