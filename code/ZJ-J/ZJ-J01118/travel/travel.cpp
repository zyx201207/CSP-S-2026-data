#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		a[0]=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			a[1]=1;
			if(s2[2]<='C'&&s4[2]<='C'||s2[2]>'C'&&s4[2]>'C'){
				a[2]=1;
				int k=(int)s2[2]-(int)s4[2];
				if(abs(k)==1){
					a[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++) cout<<a[i];
} 
