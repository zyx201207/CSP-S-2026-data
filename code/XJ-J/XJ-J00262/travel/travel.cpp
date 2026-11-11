#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1;
	cin>>s1;
	cin>>n2;
	cin>>s2;
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	char m1=s1[2];
	char m2=s2[2];
	if(n1==n2){
		cout<<'1';
		if(p1==p2){
			cout<<'1';
			if((m1<='C' && m2<='C') || (m1>='D' && m2>='D')){
				cout<<'1';
				if(abs(m1-m2)==1){
					cout<<'1';
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
