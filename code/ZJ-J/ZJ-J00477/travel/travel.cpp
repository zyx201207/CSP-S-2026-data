#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb,s1,s2,s3,s4;
	char a[5];
	cin>>s1;
	cin>>s2>>s3>>s4;
	if(s1==s3){
		a[0]='1';
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			a[1]='1';
			if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='E'&&s4[2]>='D'&&s4[2]<='E')){
				a[2]='1';
				if(abs(s2[2]-s4[2])==1){
					a[3]='1';
					for(int i=0;i<4;i++){
						cout<<a[i];
					}
					return 0;
				}else{
					a[3]='0';
					for(int i=0;i<4;i++){
						cout<<a[i];
					}
					return 0;
				}
			}else{
				a[2]='0';
				a[3]='0';
				for(int i=0;i<4;i++){
					cout<<a[i];
				}
				return 0;
			}
		}else{
			a[1]='0';
			a[2]='0';
			a[3]='0';
			for(int i=0;i<4;i++){
				cout<<a[i];
			}
			return 0;
		}
	}else{
		a[0]='0';
		a[1]='0';
		a[2]='0';
		a[3]='0';
		for(int i=0;i<4;i++){
			cout<<a[i];
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
