#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	string ax,bx,ay,by;
	cin>>ax>>ay>>bx>>by;
	if(ax==bx){
		int a=(ay[0]-'0')*10+(ay[1]-'0');
		int b=(by[0]-'0')*10+(by[1]-'0');
		string ac,bc;
		ac[0]=ay[2];
		bc[0]=by[2];
		if(a==b){
			if('A'<=ac[0]&&ac[0]<='C'&&'A'<=bc[0]&&bc[0]<='C'){
				if(!(ac[0]=='A'&&bc[0]=='C'||ac[0]=='C'&&bc[0]=='A')){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else if('D'<=ac[0]&&ac[0]<='E'&&'D'<=bc[0]&&bc[0]<='E'){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
