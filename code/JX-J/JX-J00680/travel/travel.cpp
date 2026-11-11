#include<bits/stdc++.h>
using namespace std;
bool a1=0,a2=0,a3=0,a4=0;
char c1[10],c2[10],s1[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>c1;
		cin>>s1;
		cin>>c2;
		cin>>s2;
	if(c1[0]==c2[0] and c1[1]==c2[1]){
		a1=1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			a2=1;
			if((s1[2]-'D'>=0 and s2[2]-'D'>=0) or (s1[2]-'D'<0 and s2[2]-'D'<0)){
				a3=1;
				if(s1[2]==s2[2]){
					a4=1;
					cout<<a1<<a2<<a3<<a4;
				}
				else
					cout<<a1<<a2<<a3<<a4;
			}
			else
				cout<<a1<<a2<<a3<<a4;
		}
		else
			cout<<a1<<a2<<a3<<a4;
	}
	else
		cout<<a1<<a2<<a3<<a4;
    return 0;
}
