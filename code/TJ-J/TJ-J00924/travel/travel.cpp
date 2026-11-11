#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int c=(int)(s1[2]),d=(int)(s2[2]);
			if((c<=67&&d<=67)||(c<=69&&d<=69)){
				cout<<1;
				if(abs(c-d)==1){
					cout<<1;
				}else cout<<0;
			}else cout<<00;
		}else cout<<000;
	}else cout<<0000;
	return 1;
}
