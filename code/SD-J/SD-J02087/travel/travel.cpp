#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int n,m;
	cin>>n>>s1>>m>>s2; 
	if(n==m){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if((s1[2]>='D'&& s2[2]<='C') || (s1[2]<='C' && s2[2]>='D')){
				cout<<"1100";
			}
			else{
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2] || (s1[2]=='D' &&s2[2]=='F') ||(s1[2]=='F' &&s2[2]=='D')){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
