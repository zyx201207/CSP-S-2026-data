#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=0,b=0,c=0,d=0,z=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				continue;
			}
			else{
				z=0;
				break;
			}
		}
		if(z==1){
			b=1;
			if((('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C'))||(('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F'))){
				c=1;
				if(('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F')){
					cout<<"1111";
					return 0;
				}
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					d=1;
					cout<<a<<b<<c<<d;
				}
				else{
					cout<<a<<b<<c<<d;
				}
			}
			else{
				cout<<a<<b<<c<<d;
			}
		}
		else{
			cout<<a<<b<<c<<d;
		}
	}
	else{
		cout<<a<<b<<c<<d;
	}
	return 0;
}