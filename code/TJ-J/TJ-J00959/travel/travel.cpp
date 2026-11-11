#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1==s2)
		cout<<"1";
	if(c1!=c2)
		cout<<"0";
	if(s1<=3&&s2<=3)
		cout<<"1";
	if(s1<=3&&s2>3||s1>3&&s2<=3)
		cout<<"0";
	if(s1+1==s2||s1-1==s2||s2+1==s1||s2-1==s1)
		cout<<"1";
	else cout<<"0";
    fclose(stdin);
	fclose(stdin);
	return 0;
}
