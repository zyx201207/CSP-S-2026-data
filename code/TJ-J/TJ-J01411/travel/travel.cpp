#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,R = 0,X = 0,s = 0;
	char a1,a2;
	char a[10] = {'A','B','C'};
	char b[10] = {'D','F'};
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2 && c1 != 1 && c1 != 16){
		cout<<1;
		if(s1.substr(0,2) == s2.substr(0,2)){
			cout<<1;
			for(int i = 0;i <= 2;i++){
				if(s1[2] == a[i]){
					R = 1;
				}
				if(s2[2] == a[i]){
					X = 1;
				}
			}
			for(int i = 0;i <= 1;i++){
				if(s1[2] == b[i]){
					R = 2;
				}
				if(s2[2] == b[i]){
					X = 2;
				}
			}
			if(R == X){
				cout<<1;
				a1 = s1[2];
				a2 = s2[2];
				if(R == 1){
					if(a1 == 'A' && a2 == 'B'){
						cout<<1;
						s = 1;
					}
					if(a1 == 'B' && a2 == 'A'){
						cout<<1;
						s = 1;
					}
					if(a1 == 'B' && a2 == 'C'){
						cout<<1;
						s = 1;
					}
					if(a1 == 'C' && a2 == 'B'){
						cout<<1;
						s = 1;
					}
				}else{
					if(a1 == 'D' && a2 == 'F'){
						cout<<1;
						s = 1;
					}
					if(a1 == 'F' && a2 == 'D'){
						cout<<1;
						s = 1;
					}
				}
				if(s == 0){
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
