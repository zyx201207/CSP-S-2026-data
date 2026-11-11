#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,sum=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				sum++;
			}
		}
		if(sum==2){
			cout<<'1';
			if(s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C'||s1[s1.size()-1]>'C'&&s2[s2.size()-1]>'C'){
				cout<<'1';
				if(int(s1[s1.size()-1])+1==int(s2[s2.size()-1])||int(s1[s1.size()-1])==int(s2[s2.size()-1])+1){
					cout<<'1';
				}else{
					cout<<'0';
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
