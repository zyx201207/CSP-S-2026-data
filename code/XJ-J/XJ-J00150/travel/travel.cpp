#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int a=(s1[0]-'0')*10+s1[1]-'0',b=(s2[0]-'0')*10+s2[1]-'0';
	char ch1=s1[2],ch2=s2[2];
	bool f=((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))||((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F'));
	if(c1==c2){
		cout<<"1";
		if(c1==c2&&a==b){
			cout<<"1";
			if(c1==c2&&a==b&&f){
				cout<<"1";
				if(c1==c2&&a==b&&f&&(((ch1+1==ch2)||(ch1-1==ch2))||((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')))){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	//cout<<endl<<a<<""<<b<<endl<<ch1<<" "<<ch2<<endl<<f<<endl;
	return 0;
}
