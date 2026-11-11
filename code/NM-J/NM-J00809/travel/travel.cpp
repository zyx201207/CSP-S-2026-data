#include<bits/stdc++.h>

using namespace std;

int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
		if(s1[0]+s1[1] == s2[0]+s2[1]){
			cout<<1;
			if(s1[3] == 'D' && s2[3] == 'E'){
				cout<<1<<1;
			}else if(s1[3] == 'E' && s2[3] == 'D'){
				cout<<1<<1;
			}else if(s1[3] == 'A' && s2[3] == 'B'){
				cout<<1<<1;
			}else if(s1[3] == 'A' && s2[3] == 'C'){
				cout<<1<<0;
			}else if(s1[3] == 'B' && s2[3] == 'C'){
				cout<<1<<1;
			}else if(s1[3] == 'B' && s2[3] == 'A'){
				cout<<1<<1;
			}else if(s1[3] == 'C' && s2[3] == 'A'){
				cout<<1<<0;
			}else if(s1[3] == 'C' && s2[3] == 'B'){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
    return 0;
}
