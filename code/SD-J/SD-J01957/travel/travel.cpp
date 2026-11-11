#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
	} 
	else{
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
		}
		else{
			cout<<1;
			int flag1,flag2;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				flag1=1;
			}
			else flag1=0;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				flag2=1;
			}
			else flag2=0;
			if(flag1!=flag2){
				cout<<"00";
			}
			else{
				cout<<1;
				if((flag1&&(s1[2]=='B'||s2[2]=='B'))||(!flag1)){
					cout<<1;
				}
				else cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
