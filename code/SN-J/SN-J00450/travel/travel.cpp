#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1,c2,s1,s2;
	if(c1==c2+1||c1==c2-1||c2==c1+1||c1==c1-1){
		cout<<c1<<c2<<s1<<s2;
	}
	
	return 0;
} 
