#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2,c1,c2,a,b;
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1==c2){
		if(a==b){
			if(s1!=s2){
				cout<<"1111"; 
			}
				else{
					cout<<"0000";
				}
		}
		else{
			cout<<"1110";
		}		
	}
	else{
		cout<<"0000";
	}
	return 0;
}
