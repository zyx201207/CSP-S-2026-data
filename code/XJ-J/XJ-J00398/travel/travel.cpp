#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	char c1,s1,c2,s2;
	cin>>r>>x;
	cin>>c1>>s1>>c2>>s2;
	if(s1!=s2!=c1!=c2)
	   cout<<"0";
	for(int i=0;i<=0;i++){
		if(s1==s2)
		   cout<<"1";
		else
		   cout<<"0";
		if(c1==c2)
		   cout<<"1";
		else
		   cout<<"0";
		if(s1==c1)
		   cout<<"0";
		if(s2==c2)
		   cout<<"0";
	}
	cout<<c1<<s1<<c2<<s2;
	return 0;
}