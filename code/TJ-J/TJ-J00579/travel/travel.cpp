#include<iostream>
#include<string>
using namespace std;
int c1,c2;
string s1s,s2s;
int sti(string s){
	char o=s[0],t=s[1];
	return (o-'0')*10+(t-'0');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1s>>c2>>s2s;
    char z=s1s[s1s.size()-1],m=s2s[s2s.size()-1];
    int s1=sti(s1s),s2=sti(s2s);
    if (c1==c2){
    	cout<<1;
    	if (s1==s2){
    		cout<<1;
    		if ((z<='C'&&m<='C')||(z>'C'&&m>'C')){
    			cout<<1;
    			if (z-m==1||z-m==-1){
    				cout<<1;
				}
				else cout<<0;
				//cout<<' '<<z<<' '<<m<<' '<<z-m<<endl;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
