#include<bits/stdc++.h>
using namespace std;
int main() {
	//(tarvel.in)
	//(travel.out)
	char c1,c2;
	string  s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2) {
		cout<<1;
	} 
	else if(c1!=c2){
		cout<<0;
	}
	if(s1=s2) {
		cout<<1;
	} 
	else if(s1!=s2){
		cout<<0;
	}
	if(s1=c2) {
		cout<<1;
	} 
	else if(s1!=c2){
		cout<<0;
	}
	if(c1=s2) {
		cout<<1;
	} 
	else if(c1!=s2){
		cout<<0;
	}
	return 0;
}