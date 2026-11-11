#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
string s,s1,s2,s3;
long long a,b;
bool f,f1;
char h,h1;
int main(){
	fre();
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
		a=(s1[0]-'0')*10+(s1[1]-'0');
		b=(s3[0]-'0')*10+(s3[1]-'0');
		if(a==b){
			cout<<1;
			h=s1[2];
			h1=s3[2];
			f=( 'A'<=h&&h<='C' ? 1 : 0 );
			f1=( 'A'<=h1&&h1<='C' ? 1 : 0 );
			if(f==f1){
				cout<<1;
				if(abs(h-h1)==1){
					cout<<1;
				}
				else{
					cout<<0;
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
}
