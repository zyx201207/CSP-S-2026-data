//胡嘉骏 SN-J00755 陕西省西安爱知中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,s;
	string m,w;
	cin>>n>>m>>s>>w;
	if(n==s){
		cout<<"1";
		if(m[0]==w[0] && m[1]==w[1]){
			cout<<"1";
			if(m[2]=='D'||m[2]=='F'){
				if(w[2]=='F'||w[2]=='D'){
					cout<<"1"<<"1";
				}
				else{
					cout<<"0"<<"0";
				}
			}
			else if(w[2]=='F'||w[2]=='D'){
				cout<<"0"<<"0";
			}
			else{
				cout<<"1";
				if(m[2]-1==w[2]||w[2]-1==m[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
		}
		else{
			cout<<"0"<<"0"<<"0";
		}
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}
