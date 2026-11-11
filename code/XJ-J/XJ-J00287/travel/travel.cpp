#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","n",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(c1=c2){
		if(s1[1]=s2[1]){
			if(s1[1]=s2[1]){
				if(s1[2]=s2[2]){
					cout<<"1111";
				}
				cout<<"1110";
			}
			cout<<"1100";
		}
		cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}