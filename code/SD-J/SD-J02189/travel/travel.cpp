#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	int a=1;
	cin>>s>>s1>>s2>>s3;
	if(s[1]==s2[1] && s[0]==s2[0]){
		printf("%d",a);
		if(s1[1]==s3[1] && s1[0]==s3[0]){
			printf("%d",a);
			if(s1[2]<='C' && s3[2]<='C'){
				printf("%d",a);
				if(s1[2]+1==s3[2] || s1[2]==s3[2]+1){
					printf("%d",a);
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(s1[2]>='D' && s3[2]>='D'){
				cout<<"11";
				return 0;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
