#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c,d;
	cin>>a>>c>>b>>d;
	
	if(a==b+1){
		if(c-'a'==d-'r'||d-'a'==c-'r')
		cout<<"1111";
		else if(c-'a'==d-'t'||d-'a'==c-'t')
		cout<<"1110";
		else if(c-'a'==d-'u'||d-'a'==c-'u')
		cout<<"1100";
			else if(c-'a'==d-'v'||d-'a'==c-'v')
		cout<<"1100";
	}
else cout<<"0000";
return 0;
	}
	

