#include <iostream>
using namespace std;
int main()
{
	int c1,c2,s1[3],s2[3],n;
	cin>>c1>>c2>>n;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(c1==c2){
		cout<<1;
	}
	if else(c1=!c2){
		cout<<0;
	}
	if(s1[0][1]==s2[0][1]){
		cout<<1;
	}
	if else(s1[0][1]=!s2[0][1]){
		cout<<0;
	}
	if(s1[2]==s2[2]-1){
		cout<<1;
	}
	else{
		cout>>0;
	}
	if(s1[2]==s2[2]+1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}