//陈晨宸 SN-J00761 西安市第八十二中学
#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1-s2==1){
		cout<<"1111";
	}
	return 0;
}
