#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.out","r",stdin);
	freopen("travel.in","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=1,b=1,c=1,d=1;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			a=0;
			cout<<0<<0<<0<<0;
		} 
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			b=0;
		 cout<<a<<0<<0<<0;
		}	
	}
	int len=s1.size();
	int xy=s1[len-1];
	int yx=s2[len-1];
	for(int i=0;i<s2.size()-1;i++){
		if(s1[i]==s2[i+1]){
			c=0;
			 cout<<a<<b<<0<<0;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
