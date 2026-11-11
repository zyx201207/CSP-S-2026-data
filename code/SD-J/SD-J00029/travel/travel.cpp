#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a = s1.substr(0,2);
	string b = s2.substr(0,2);
	char c = s1[2];
	char d = s2[2];
	if(c1 == c2){
		cout<<1;
		if(a == b){
			cout<<1;
			if((c >= 'A' && c <= 'C' && d >= 'A' && d <= 'C') || (c >= 'E' && c <= 'F' && d >= 'E' && d <= 'F')){
				cout<<1;
				if(abs(c - d) == 1){
					cout<<1;
				}else{
					cout<<0;
				}
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

