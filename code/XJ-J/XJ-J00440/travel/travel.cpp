#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string str1,str2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>str1>>b>>str2;
	c=str1[0]+str1[1];
	d=str2[0]+str2[1];
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			int k=str1[2]-'0';
			int l=str2[2]-'0';
			if(k<=19&&l<=19){
				cout<<1;
				if((k+1==l)||(k-1==l))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}