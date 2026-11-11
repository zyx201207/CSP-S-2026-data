#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a=0;
int main(){
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		for(int i=0;i<2;i++){
			if(c2[i]==c4[i]) a++;
		}
		if(a==2){
			cout<<1;
			if(c2[2]=='A'||c2[2]=='C'||c2[2]=='B'){
				if(c4[2]=='A'||c4[2]=='C'||c4[2]=='B'){
					cout<<1;
					if(c2[2]=='A'||c4[2]=='C'){
						if(c2[2]!='B'|| c4[2]!='B'){
							cout<<0;
							return 0;
						}
						else cout<<1;
					}
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			if(c2[2]=='D'||c2[2]=='F'){
				if(c4[2]=='D'||c4[2]=='F'){
					cout<<1<<1;
				}
				else cout<<0<<0;
				return 0;
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
