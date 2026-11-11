#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1[0]==c_2[0]&&c_1[1]==c_2[1]){
		cout<<1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			cout<<1;
			if(s_1[2]=='D'||s_1[2]=='F'){
				if(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C'){
					cout<<0<<0;
					return 0;
				}
				else{
					cout<<1<<1;
				}
			}
			else if(s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C'){
				if(s_2[2]=='D'||s_2[2]=='F'){
					cout<<0<<0;
					return 0;
				}
				else{
					cout<<1;
					if(s_1[2]=='A'){
						if(s_2[2]=='B'){
							cout<<1;
						}
						else{
							cout<<0;
							return 0;
						}
					}
					else if(s_1[2]=='B'){
						if(s_2[2]=='A'||s_2[2]=='C'){
							cout<<1;
						}
						else{
							cout<<0;
							return 0;
						}
					}
					else if(s_1[2]=='C'){
						if(s_2[2]=='B'){
							cout<<1;
						}
						else{
							cout<<0;
							return 0;
						}
					}
				}
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}

	return 0;
}

