#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c[3],s[3];
	for(int i=0;i<2;i++){
		cin>>c[i]>>s[i];
	}
	char a=s[0][2];
	if(a<s[1][2]){
		a=s[1][2];
	}
	if(c[0]==c[1]){
		cout<<1;
		if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
			cout<<1;
			if(abs(s[0][2]-s[1][2])<=2&&a!='D'){
				cout<<1;
				if(abs(s[0][2]-s[1][2])==1){
					cout<<1;
				}else{              
					cout<<0;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
